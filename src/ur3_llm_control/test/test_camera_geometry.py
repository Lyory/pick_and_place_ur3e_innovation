"""Recover the grasp centre from a visible cube silhouette, not its biased centroid."""
import sys
from pathlib import Path
import cv2
import numpy as np
import pytest
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'scripts'))
from camera_state import estimate_cube_center


@pytest.mark.parametrize('center,yaw,top', [
    ((.312, -.261), 0.0, .785),  # deliberately off-centre inside Zone A
    ((.30, 0), .12, .785),
    ((.29, .27), -.20, .785),
    ((.42, -.18), 0.0, .78),
    ((.48, .15), .30, .78),
    ((.40, .12), 0.0, .78),
])
def test_top_square_fit_removes_side_face_bias(center, yaw, top):
    origin = np.array([.4, 0, 1.07])
    rot = np.array([[0, -1, 0], [-1, 0, 0], [0, 0, -1]])
    focal = 480/np.tan(1.1)
    k = [focal, 0, 480, 0, focal, 360, 0, 0, 1]
    turn = np.array([[np.cos(yaw), -np.sin(yaw)], [np.sin(yaw), np.cos(yaw)]])
    square = np.array([[-.02, -.02], [.02, -.02], [.02, .02], [-.02, .02]]) @ turn.T + center
    # A colour silhouette includes both top and bottom corners of visible sides.
    vertices = np.array([[x, y, z] for z in (top, top-.04) for x, y in square])
    camera = (vertices-origin) @ rot
    pixels = camera[:, :2]/camera[:, 2:3]*focal + np.array([480, 360])
    contour = cv2.convexHull(np.rint(pixels).astype(np.float32))
    fitted = estimate_cube_center(contour, origin, rot, k, top, .04)
    assert fitted is not None
    assert np.linalg.norm(fitted-np.array(center)) < .003


def test_zone_b_gripper_occludes_one_far_edge():
    origin = np.array([.4, 0, 1.07])
    rot = np.array([[0, -1, 0], [-1, 0, 0], [0, 0, -1]])
    focal = 480/np.tan(1.1)
    k = [focal, 0, 480, 0, focal, 360, 0, 0, 1]
    # Masking part of the left top edge replaces it with a diagonal boundary;
    # the bottom top edge remains complete. Side faces extend the right edge.
    outline = np.array([[.330, .018], [.326, .020], [.289, .020],
                        [.280, -.020], [.320, -.020], [.330, -.018]])
    points = np.column_stack((outline, np.full(len(outline), .785)))
    camera = (points-origin) @ rot
    pixels = camera[:, :2]/camera[:, 2:3]*focal + np.array([480, 360])
    contour = cv2.convexHull(pixels.astype(np.float32))
    center = estimate_cube_center(contour, origin, rot, k, .785, .04)
    assert center is not None
    assert np.linalg.norm(center-np.array([.30, 0])) < .002
