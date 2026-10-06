#!/usr/bin/env python3
"""Detect cubes with the wrist camera, projecting pixels through live camera TF."""
import math
from collections import deque
import time
from pathlib import Path
import cv2
import numpy as np
import yaml
import rclpy
from rclpy.node import Node
from rclpy.time import Time
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image, CameraInfo
from tf2_ros import Buffer, TransformListener, TransformException
from ament_index_python.packages import get_package_share_directory
from ur3_llm_control.srv import GetWorldState

COLORS = {
    'red_cube': ((0, 90, 85), (10, 255, 255)),
    'yellow_cube': ((18, 90, 85), (36, 255, 255)),
    'blue_cube': ((95, 90, 70), (130, 255, 255)),
    'green_cube': ((38, 70, 60), (88, 255, 255)),
    'purple_cube': ((132, 65, 60), (170, 255, 255)),
}


def rotation(q):
    x, y, z, w = q.x, q.y, q.z, q.w
    return np.array([[1-2*(y*y+z*z), 2*(x*y-z*w), 2*(x*z+y*w)],
                     [2*(x*y+z*w), 1-2*(x*x+z*z), 2*(y*z-x*w)],
                     [2*(x*z-y*w), 2*(y*z+x*w), 1-2*(x*x+y*y)]])


def estimate_cube_center(contour, origin, rot, intrinsics, top, cube_size):
    """Fit the square top from its two far silhouette edges.

    The colour mask includes side faces. Projecting its centroid onto the top
    plane biases the grasp toward the camera, especially inside a tray. The
    edges facing away from the camera belong to the actual top square; side
    faces extend the silhouette only toward the camera. Fit those edges and
    offset inward by half the configured cube width. No zone-centre snapping.
    """
    pixels = contour.reshape(-1, 2).astype(float)
    camera_rays = np.column_stack(((pixels[:, 0]-intrinsics[2])/intrinsics[0],
                                  (pixels[:, 1]-intrinsics[5])/intrinsics[4],
                                  np.ones(len(pixels))))
    rays = camera_rays @ rot.T
    if np.any(rays[:, 2] >= -.1):
        return None
    xy = (origin + rays * ((top-origin[2])/rays[:, 2])[:, None])[:, :2]
    hull = cv2.convexHull(xy.astype(np.float32))
    polygon = cv2.approxPolyDP(hull, .0015, True).reshape(-1, 2).astype(float)
    if len(polygon) < 4:
        return None
    area = np.sum(polygon[:, 0]*np.roll(polygon[:, 1], -1) -
                  polygon[:, 1]*np.roll(polygon[:, 0], -1))
    if area < 0:
        polygon = polygon[::-1]
    edges = []
    all_edges = []
    for a, b in zip(polygon, np.roll(polygon, -1, axis=0)):
        delta = b-a
        length = np.linalg.norm(delta)
        if not .60*cube_size <= length <= 1.35*cube_size:
            continue
        outward = np.array([delta[1], -delta[0]])/length
        midpoint = (a+b)/2
        all_edges.append((outward, midpoint, length))
        if np.dot(outward, origin[:2]-midpoint) >= 0:
            continue
        edges.append((outward, np.dot(outward, midpoint)-cube_size/2, length))
    candidates = []
    for i, (n1, d1, length1) in enumerate(edges):
        for n2, d2, length2 in edges[i+1:]:
            if abs(np.dot(n1, n2)) > .20:
                continue
            center = np.linalg.solve(np.array([n1, n2]), np.array([d1, d2]))
            # Prefer two complete cube-width edges rather than small noisy facets.
            score = abs(length1-cube_size)+abs(length2-cube_size)
            candidates.append((score, center))
    if candidates:
        return min(candidates, key=lambda c: c[0])[1]
    # A finger can mask part of one far edge (notably at Zone B). A complete
    # far edge still fixes the top centre: its midpoint plus half a cube inward.
    # Require an opposite parallel edge to reject diagonal occlusion boundaries.
    complete = []
    for normal, midpoint, length in all_edges:
        if not .90*cube_size <= length <= 1.05*cube_size:
            continue
        if np.dot(normal, origin[:2]-midpoint) >= 0:
            continue
        if not any(np.dot(normal, other) < -.98 for other, _, _ in all_edges):
            continue
        complete.append((abs(length-cube_size), midpoint-normal*cube_size/2))
    return min(complete, key=lambda c: c[0])[1] if complete else None


class CameraState(Node):
    def __init__(self):
        super().__init__('camera_state')
        scene = yaml.safe_load((Path(get_package_share_directory('ur3_llm_control')) /
                                'config/scene.yaml').read_text())
        self.frame = scene['frame_id']
        self.base_height = scene['robot_base_height']
        table = scene['table']
        self.table_top = table['z'] + table['size'][2] / 2
        self.cube_size = scene['cube_size']
        self.bounds = (table['x']-table['size'][0]/2, table['x']+table['size'][0]/2,
                       table['y']-table['size'][1]/2, table['y']+table['size'][1]/2)
        self.zones = scene['zones']
        self.detections = {}
        self.last_frame = 0.0
        self.calibration = None
        self.pending = deque(maxlen=6)
        self.tf = Buffer()
        self.listener = TransformListener(self.tf, self)
        self.create_subscription(CameraInfo, '/task_camera/camera_info', self.on_info,
                                 qos_profile_sensor_data)
        self.create_subscription(Image, '/task_camera/image_raw', self.on_image,
                                 qos_profile_sensor_data)
        self.create_service(GetWorldState, '/camera_world_state', self.on_state)
        self.create_timer(.05, self.process_pending)

    def on_info(self, msg):
        if msg.k[0] > 0 and msg.k[4] > 0:
            self.calibration = msg

    def on_image(self, msg):
        self.pending.append(msg)

    def process_pending(self):
        # Image and joint TF arrive independently. Give the exact image-time TF
        # a chance to arrive instead of dropping every image ahead of joint TF.
        for msg in reversed(self.pending):
            if self.tf.can_transform(self.frame, msg.header.frame_id,
                                     Time.from_msg(msg.header.stamp)):
                self.process_image(msg)
                self.pending.clear()
                return

    def process_image(self, msg):
        info = self.calibration
        if info is None or (info.width, info.height) != (msg.width, msg.height):
            return
        if msg.encoding not in ('rgb8', 'bgr8') or msg.step < msg.width * 3:
            return
        try:
            transform = self.tf.lookup_transform(self.frame, msg.header.frame_id,
                                                 Time.from_msg(msg.header.stamp)).transform
        except TransformException:
            # Reject images without a matching pose; never use a fixed camera pose.
            return
        origin = np.array([transform.translation.x, transform.translation.y,
                           transform.translation.z + self.base_height])
        rot = rotation(transform.rotation)
        pixels = np.frombuffer(msg.data, dtype=np.uint8).reshape(msg.height, msg.step)
        pixels = pixels[:, :msg.width * 3].reshape(msg.height, msg.width, 3)
        hsv = cv2.cvtColor(pixels, cv2.COLOR_RGB2HSV if msg.encoding == 'rgb8'
                           else cv2.COLOR_BGR2HSV)
        detections = {}
        for name, (lower, upper) in COLORS.items():
            mask = cv2.inRange(hsv, np.array(lower), np.array(upper))
            if name == 'red_cube':
                mask |= cv2.inRange(hsv, np.array((170, 90, 85)),
                                    np.array((179, 255, 255)))
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            candidates = [c for c in contours if 25 <= cv2.contourArea(c) <= msg.width*msg.height*.08]
            if not candidates:
                continue
            contour = max(candidates, key=cv2.contourArea)
            moment = cv2.moments(contour)
            if not moment['m00']:
                continue
            u, v = moment['m10']/moment['m00'], moment['m01']/moment['m00']
            ray = rot @ np.array([(u-info.k[2])/info.k[0],
                                  (v-info.k[5])/info.k[4], 1.0])
            if ray[2] >= -0.1:
                continue
            # Use the silhouette centroid only to select the support plane.
            # The grasp point itself comes from fitting the cube's top edges.
            top = self.table_top + self.cube_size
            coarse = origin + ray * ((top-origin[2])/ray[2])
            location = next((zone for zone, p in self.zones.items()
                             if math.hypot(coarse[0]-p['x'], coarse[1]-p['y']) < .065), 'table')
            if location != 'table':
                top = self.zones[location]['z'] + .0025 + self.cube_size
            center = estimate_cube_center(contour, origin, rot, info.k, top, self.cube_size)
            if center is None:
                continue
            x, y = float(center[0]), float(center[1])
            xmin, xmax, ymin, ymax = self.bounds
            if not (xmin <= x <= xmax and ymin <= y <= ymax):
                continue
            location = next((zone for zone, p in self.zones.items()
                             if math.hypot(x-p['x'], y-p['y']) < .052), 'table')
            detections[name] = (location, x, y)
        self.detections = detections
        self.last_frame = time.monotonic()

    def on_state(self, _request, response):
        response.camera_ready = time.monotonic()-self.last_frame < 2.0
        if response.camera_ready:
            for name, (location, x, y) in sorted(self.detections.items()):
                response.objects.append(name)
                response.locations.append(location)
                response.x.append(x)
                response.y.append(y)
        return response


def main():
    rclpy.init()
    node = CameraState()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
