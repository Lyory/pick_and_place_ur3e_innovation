#!/usr/bin/env python3
"""Local physics regression for the explicit purple-to-Zone-A skill plan."""
import threading
import rclpy
from rclpy.executors import MultiThreadedExecutor
from demo_occupied_zone import Demo


def main():
    rclpy.init()
    node = Demo()
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)
    thread = threading.Thread(target=executor.spin, daemon=True)
    thread.start()
    try:
        state = node.state()
        print('INITIAL CAMERA:', state, flush=True)
        state = node.execute_plan([
            {'skill': 'detect_objects'},
            {'skill': 'check_zone', 'zone': 'zone_a'},
            {'skill': 'find_object', 'object': 'purple_cube'},
            {'skill': 'pick', 'object': 'purple_cube'},
            {'skill': 'place', 'object': 'purple_cube', 'zone': 'zone_a'},
            {'skill': 'home'},
        ], state)
        if state['held_object'] or state['locations']['purple_cube'] != 'zone_a':
            raise RuntimeError('Wrist camera did not confirm purple in Zone A')
        print('DEMO SUCCESS: purple_cube in zone_a', flush=True)
    finally:
        executor.shutdown()
        thread.join(timeout=2)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
