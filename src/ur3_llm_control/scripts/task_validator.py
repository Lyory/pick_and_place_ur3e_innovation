#!/usr/bin/env python3
"""Validate syntax, whitelist, and sequential robot state before execution."""
import json
import re
from pathlib import Path
import yaml
from ament_index_python.packages import get_package_share_directory

VALID_SKILLS = {"detect_objects", "check_zone", "find_object", "find_free_position", "home", "pick", "place"}
VALID_OBJECTS = {"red_cube", "yellow_cube", "blue_cube", "green_cube", "purple_cube"}
VALID_ZONES = {"zone_a", "zone_b", "zone_c", "buffer", "temp_1", "temp_2"}
# One source of destination geometry for perception, validation and robot skills.
_SCENE = yaml.safe_load((Path(get_package_share_directory("ur3_llm_control")) /
                         "config/scene.yaml").read_text(encoding="utf-8"))
ZONE_XY = {name: (point['x'], point['y']) for name, point in _SCENE['zones'].items()}
TASK_MAP = {
    0: {"zone_a": "red_cube", "zone_b": "yellow_cube", "zone_c": "blue_cube"},
    1: {"zone_a": "red_cube", "zone_b": "blue_cube", "zone_c": "yellow_cube"},
    2: {"zone_a": "yellow_cube", "zone_b": "red_cube", "zone_c": "blue_cube"},
    3: {"zone_a": "yellow_cube", "zone_b": "blue_cube", "zone_c": "red_cube"},
    4: {"zone_a": "blue_cube", "zone_b": "red_cube", "zone_c": "yellow_cube"},
    5: {"zone_a": "blue_cube", "zone_b": "yellow_cube", "zone_c": "red_cube"},
}


class ValidationError(Exception):
    def __init__(self, status, message):
        self.status = status
        super().__init__(message)


def student_mapping(config_path=None, *, suffix=None):
    if suffix is None:
        path = Path(config_path or (
            Path(get_package_share_directory("ur3_llm_control")) / "config/student_config.yaml"
        ))
        student = yaml.safe_load(path.read_text(encoding="utf-8"))["student"]
        student_id = str(student.get("id", ""))
        suffix = student_id[-2:]
    if not isinstance(suffix, str) or not re.fullmatch(r"[0-9]{2}", suffix):
        raise ValidationError("INVALID_STUDENT_ID", "Enter a two-digit student ID suffix")
    return TASK_MAP[int(suffix) % 6]


def validate(plan_document, world_state):
    if isinstance(plan_document, str):
        try:
            plan_document = json.loads(plan_document)
        except json.JSONDecodeError as exc:
            raise ValidationError("INVALID_JSON", "Plan must be JSON") from exc
    if not isinstance(plan_document, dict) or set(plan_document) != {"plan"}:
        raise ValidationError("INVALID_PLAN", "Expected exactly one top-level 'plan' key")
    steps = plan_document["plan"]
    if not isinstance(steps, list) or not steps or len(steps) > 80:
        raise ValidationError("INVALID_PLAN", "Plan must contain 1 to 80 steps")
    if not isinstance(world_state, dict):
        raise ValidationError("INVALID_STATE", "World state is unavailable")
    locations = world_state.get("locations", {})
    held = world_state.get("held_object", "")
    if set(locations) != VALID_OBJECTS or held not in VALID_OBJECTS | {""}:
        raise ValidationError("INVALID_STATE", "World state has unexpected objects")
    locations = dict(locations)
    positions = dict(world_state.get("positions", {}))
    if set(positions) != VALID_OBJECTS:
        raise ValidationError("INVALID_STATE", "Camera positions are missing")
    if held and locations[held] != "held":
        raise ValidationError("INVALID_STATE", "Held object state is inconsistent")
    normalized = []
    detected = False
    found = set()
    checked = set()
    free = set()
    for index, step in enumerate(steps, 1):
        if not isinstance(step, dict) or "skill" not in step:
            raise ValidationError("INVALID_STEP", f"Step {index} must be an object with skill")
        if set(step) - {"skill", "object", "zone"}:
            raise ValidationError("INVALID_STEP", f"Step {index} has unexpected keys")
        skill = step["skill"]
        if skill not in VALID_SKILLS:
            raise ValidationError("INVALID_SKILL", f"Step {index}: {skill}")
        obj = step.get("object", "")
        zone = step.get("zone", "")
        if not isinstance(obj, str) or not isinstance(zone, str):
            raise ValidationError("INVALID_STEP", f"Step {index} arguments must be strings")
        if skill == "detect_objects":
            if obj or zone:
                raise ValidationError("INVALID_STEP", "detect_objects takes no arguments")
            detected = True
        elif skill == "find_object":
            if not detected or obj not in VALID_OBJECTS or zone:
                raise ValidationError("INVALID_STEP", "find_object needs detection and a known object only")
            if obj == held:
                raise ValidationError("INVALID_SEQUENCE", "Cannot find an already held cube on the table")
            found.add(obj)
        elif skill in ("check_zone", "find_free_position"):
            if not detected or obj or zone not in VALID_ZONES:
                raise ValidationError("INVALID_STEP", f"{skill} needs detection and a known zone only")
            checked.add(zone)
            if skill == "find_free_position":
                if zone not in {"buffer", "temp_1", "temp_2"}:
                    raise ValidationError("INVALID_ZONE", "Temporary positions are buffer, temp_1, temp_2")
                x, y = ZONE_XY[zone]
                if any(name != held and ((positions[name][0]-x)**2 +
                                         (positions[name][1]-y)**2) < .075**2
                       for name in locations):
                    raise ValidationError("ZONE_OCCUPIED", f"{zone} is not a free temporary position")
                free.add(zone)
        elif skill == "home":
            if obj or zone:
                raise ValidationError("INVALID_STEP", "home takes no arguments")
            if held:
                raise ValidationError("INVALID_SEQUENCE", "Cannot home while holding a cube")
        elif skill == "pick":
            if obj not in VALID_OBJECTS:
                raise ValidationError("INVALID_OBJECT", f"Step {index}: {obj}")
            if zone:
                raise ValidationError("INVALID_STEP", "pick takes no zone")
            if held:
                raise ValidationError("INVALID_SEQUENCE", "Robot already holds a cube")
            if locations[obj] == "held":
                raise ValidationError("INVALID_SEQUENCE", "Cube is already held")
            if not detected or obj not in found:
                raise ValidationError("INVALID_SEQUENCE", f"find_object({obj}) must precede pick")
            found.remove(obj)
            held = obj
            locations[obj] = "held"
        else:
            if obj not in VALID_OBJECTS:
                raise ValidationError("INVALID_OBJECT", f"Step {index}: {obj}")
            if zone not in VALID_ZONES:
                raise ValidationError("INVALID_ZONE", f"Step {index}: {zone}")
            if held != obj:
                raise ValidationError("INVALID_SEQUENCE", f"Must pick {obj} before placing")
            if zone not in checked:
                raise ValidationError("INVALID_SEQUENCE", f"check_zone({zone}) must precede place")
            if zone in {"buffer", "temp_1", "temp_2"} and zone not in free:
                raise ValidationError("INVALID_SEQUENCE", f"find_free_position({zone}) must precede temporary placement")
            x, y = ZONE_XY[zone]
            if any(name != obj and ((positions[name][0] - x) ** 2 +
                                    (positions[name][1] - y) ** 2) < 0.075 ** 2
                   for name in locations):
                raise ValidationError("ZONE_OCCUPIED", f"Step {index}: {zone} is occupied")
            held = ""
            locations[obj] = zone
            positions[obj] = (x, y)
            checked.clear()
            free.clear()
            found.clear()
        normalized.append({"skill": skill, "object": obj, "zone": zone})
    if held:
        raise ValidationError("INVALID_SEQUENCE", "Plan must place the held cube")
    if not any(step["skill"] == "pick" for step in normalized):
        raise ValidationError("INVALID_SEQUENCE", "Plan must pick and place a cube")
    if normalized[-1]["skill"] != "home":
        raise ValidationError("INVALID_SEQUENCE", "Plan must finish with home")
    return normalized
