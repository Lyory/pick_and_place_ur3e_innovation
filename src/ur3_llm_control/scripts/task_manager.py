#!/usr/bin/env python3
"""Interactive or ROS-topic entry point for validated LLM tasks."""
import argparse
import json
import re
import threading
import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from std_msgs.msg import String
from ur3_llm_control.srv import GetWorldState
from llm_planner import LLMPlanner, PlannerError
from task_validator import validate, student_mapping, ValidationError, ZONE_XY
from skill_executor import SkillExecutor, SkillExecutionError


class TaskManager(Node):
    def __init__(self, topic_mode=False):
        super().__init__("task_manager_topic" if topic_mode else "task_manager")
        self.planner = None
        self.state_client = self.create_client(GetWorldState, "/get_world_state")
        self.skill_executor = SkillExecutor(self)
        self.busy = threading.Lock()
        if topic_mode:
            self.create_subscription(String, "/ur3_llm_control/command", self.on_command, 10)

    def on_command(self, msg):
        if not self.busy.acquire(blocking=False):
            self.get_logger().warning("Task already in progress")
            return
        threading.Thread(target=self._run_topic, args=(msg.data,), daemon=True).start()

    def _run_topic(self, command):
        try:
            self.run_command(command)
        finally:
            self.busy.release()

    def world_state(self):
        if not self.state_client.wait_for_service(timeout_sec=10):
            raise SkillExecutionError("SERVICE_UNAVAILABLE", "/get_world_state is unavailable")
        done = threading.Event()
        future = self.state_client.call_async(GetWorldState.Request())
        future.add_done_callback(lambda _: done.set())
        if not done.wait(90) or future.result() is None:
            raise SkillExecutionError("SERVICE_TIMEOUT", "Could not read robot world state")
        response = future.result()
        if not response.camera_ready:
            raise SkillExecutionError("CAMERA_UNAVAILABLE", "Camera cannot observe all cubes; inspect robot_skills logs for the missing cube or observation motion failure")
        locations = dict(zip(response.objects, response.locations))
        return {
            "locations": locations,
            "positions": dict(zip(response.objects, zip(response.x, response.y))),
            "zones": {zone: [obj for obj, x, y in zip(response.objects, response.x, response.y)
                             if obj != response.held_object and
                             (x-ZONE_XY[zone][0])**2 + (y-ZONE_XY[zone][1])**2 < .075**2]
                      for zone in ZONE_XY},
            "held_object": response.held_object,
        }

    def run_command(self, command):
        print("\n========================================\nUR3e LLM Robot Control\n========================================")
        print(f"USER COMMAND:\n{command}")
        try:
            print("\nOBSERVATION: Home → intermediate camera pose")
            self.skill_executor.execute([{"skill": "detect_objects", "object": "", "zone": ""}])
            state = self.world_state()
            suffix = command.strip() if re.fullmatch(r"[0-9]{2}", command.strip()) else None
            wants_student = suffix is not None or "student id" in command.lower() or "mssv" in command.lower()
            mapping = student_mapping(suffix=suffix) if wants_student else None
            if mapping is not None and all(state["locations"].get(obj) == zone
                                           for zone, obj in mapping.items()):
                print("\nTASK ALREADY COMPLETE: cubes are in their assigned zones")
                return
            if self.planner is None:
                self.planner = LLMPlanner()
            feedback = None
            for attempt in range(3):
                try:
                    document = self.planner.generate_plan(command, state, mapping, feedback=feedback)
                    steps = validate(document, state)
                    break
                except ValidationError as exc:
                    if attempt == 2:
                        raise
                    feedback = f"{exc.status}: {exc}"
                    print(f"Plan rejected ({feedback}); requesting correction")
                except PlannerError as exc:
                    if "invalid JSON" not in str(exc) or attempt == 2:
                        raise
                    feedback = "Reply must be one JSON object containing only the plan list"
                    print("Invalid JSON; requesting a corrected plan")
            if mapping is not None:
                desired = {zone: obj for zone, obj in mapping.items()}
                resulting = dict(state["locations"])
                for step in steps:
                    if step["skill"] == "place":
                        resulting[step["object"]] = step["zone"]
                if any(resulting[obj] != zone for zone, obj in desired.items()):
                    raise ValidationError("INVALID_STUDENT_PLAN", "Plan does not satisfy student ID mapping")
            print("\nLLM PLAN:")
            for i, step in enumerate(steps, 1):
                arguments = ", ".join(x for x in (step["object"], step["zone"]) if x)
                print(f"{i}. {step['skill']}({arguments})")
            print("\nEXECUTION:")
            # Verify the last placement while still at the camera pose. Home is
            # the final motion, so reading final state cannot restart observation.
            self.skill_executor.execute(steps[:-1])
            final = self.world_state()
            expected = {step["object"]: step["zone"] for step in steps
                        if step["skill"] == "place"}
            if final["held_object"] or any(final["locations"].get(obj) != zone
                                           for obj, zone in expected.items()):
                raise SkillExecutionError("FINAL_STATE_MISMATCH",
                                          "Camera does not confirm the planned placements")
            self.skill_executor.execute(steps[-1:])
            print("\n========================================\nTASK SUCCESS\n========================================")
        except (PlannerError, ValidationError, SkillExecutionError) as exc:
            status = getattr(exc, "status", "PLANNER_FAILED")
            print(f"\n========================================\nTASK FAILED: {status}\n{exc}\n========================================")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--topic", action="store_true", help="Listen on /ur3_llm_control/command")
    args = parser.parse_args(rclpy.utilities.remove_ros_args()[1:])
    rclpy.init()
    node = TaskManager(args.topic)
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()
    try:
        if args.topic:
            spin_thread.join()
        else:
            while rclpy.ok():
                try:
                    command = input("\nEnter your command\n> ").strip()
                except (EOFError, KeyboardInterrupt):
                    break
                if command:
                    node.run_command(command)
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        spin_thread.join(timeout=2.0)
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
