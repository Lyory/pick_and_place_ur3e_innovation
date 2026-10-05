#!/usr/bin/env python3
"""Physical integration demo: blue blocks Zone B, red must replace it."""
import threading
import time
import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from sensor_msgs.msg import JointState
from ur3_llm_control.srv import ExecuteSkill, GetWorldState
from task_validator import validate


class Demo(Node):
    def __init__(self):
        super().__init__('occupied_zone_demo')
        self.state_client = self.create_client(GetWorldState, '/get_world_state')
        self.skill_client = self.create_client(ExecuteSkill, '/execute_skill')
        self.fingers = {}
        self.create_subscription(JointState, '/joint_states', self.on_joints, 10)

    def on_joints(self, msg):
        for name, position in zip(msg.name, msg.position):
            if name in ('robotiq_85_left_knuckle_joint', 'robotiq_85_right_knuckle_joint'):
                self.fingers[name] = position

    def check_fingers(self, closed):
        deadline = time.monotonic() + 2.0
        while time.monotonic() < deadline:
            values = [self.fingers.get(name) for name in
                      ('robotiq_85_left_knuckle_joint', 'robotiq_85_right_knuckle_joint')]
            if all(value is not None for value in values):
                if (closed and values[0] > 0.25 and values[1] < -0.25) or (
                        not closed and all(abs(value) < 0.05 for value in values)):
                    print('FINGER JOINTS:', values, flush=True)
                    return
            time.sleep(0.05)
        raise RuntimeError('Finger joints did not reach expected opening')

    @staticmethod
    def call(client, request, timeout):
        if not client.wait_for_service(timeout_sec=30):
            raise RuntimeError('ROS service unavailable')
        done = threading.Event()
        future = client.call_async(request)
        future.add_done_callback(lambda _: done.set())
        if not done.wait(timeout) or future.result() is None:
            raise RuntimeError('ROS service timed out or failed')
        return future.result()

    def state(self):
        response = self.call(self.state_client, GetWorldState.Request(), 90)
        if not response.camera_ready or len(response.objects) != 5:
            raise RuntimeError('Camera did not detect all five cubes')
        return {
            'locations': dict(zip(response.objects, response.locations)),
            'positions': dict(zip(response.objects, zip(response.x, response.y))),
            'held_object': response.held_object,
        }

    def execute_plan(self, plan, state):
        for step in validate({'plan': plan}, state):
            request = ExecuteSkill.Request()
            request.skill, request.object, request.zone = (
                step['skill'], step['object'], step['zone'])
            result = self.call(self.skill_client, request, 180)
            arguments = ", ".join(value for value in (request.object, request.zone) if value)
            print(f"{request.skill}({arguments}): {result.status} {result.message}", flush=True)
            if not result.success:
                raise RuntimeError(f'Demo stopped: {result.status}: {result.message}')
            if request.skill in ('pick', 'place'):
                self.check_fingers(closed=request.skill == 'pick')
            state = self.state()
            print('CAMERA:', state['locations'], flush=True)
        return state

    def run_demo(self):
        state = self.state()
        print('INITIAL CAMERA:', state['locations'], flush=True)
        if any(location != 'table' for location in state['locations'].values()):
            raise RuntimeError('Reset Gazebo: all five cubes must start on the table')
        print('SETUP: robot moves blue_cube into zone_b', flush=True)
        state = self.execute_plan([
            {'skill': 'detect_objects'},
            {'skill': 'check_zone', 'zone': 'zone_b'},
            {'skill': 'find_object', 'object': 'blue_cube'},
            {'skill': 'pick', 'object': 'blue_cube'},
            {'skill': 'place', 'object': 'blue_cube', 'zone': 'zone_b'},
            {'skill': 'home'},
        ], state)
        if state['locations']['blue_cube'] != 'zone_b':
            raise RuntimeError('Camera did not confirm occupied Zone B')
        print('OCCUPIED-ZONE TASK: move red_cube into zone_b', flush=True)
        state = self.execute_plan([
            {'skill': 'detect_objects'},
            {'skill': 'check_zone', 'zone': 'zone_b'},
            {'skill': 'find_object', 'object': 'blue_cube'},
            {'skill': 'pick', 'object': 'blue_cube'},
            {'skill': 'find_free_position', 'zone': 'buffer'},
            {'skill': 'check_zone', 'zone': 'buffer'},
            {'skill': 'place', 'object': 'blue_cube', 'zone': 'buffer'},
            {'skill': 'find_object', 'object': 'red_cube'},
            {'skill': 'pick', 'object': 'red_cube'},
            {'skill': 'check_zone', 'zone': 'zone_b'},
            {'skill': 'place', 'object': 'red_cube', 'zone': 'zone_b'},
            {'skill': 'home'},
        ], state)
        if (state['locations']['red_cube'] != 'zone_b' or
                state['locations']['blue_cube'] != 'buffer' or state['held_object']):
            raise RuntimeError('Final camera state differs from plan')
        print('DEMO SUCCESS: red_cube in zone_b, blue_cube in buffer', flush=True)


def main():
    rclpy.init()
    node = Demo()
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)
    thread = threading.Thread(target=executor.spin, daemon=True)
    thread.start()
    try:
        node.run_demo()
    finally:
        executor.shutdown()
        thread.join(timeout=2)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
