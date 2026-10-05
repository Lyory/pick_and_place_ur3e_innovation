"""Purple is a valid object, including tasks that must first clear Zone A."""
import sys
from pathlib import Path
import pytest
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'scripts'))
from task_validator import validate, ValidationError


def state(occupied=False):
    positions = {'red_cube': (.42, -.18), 'yellow_cube': (.48, -.10),
                 'blue_cube': (.35, -.13), 'green_cube': (.48, .15),
                 'purple_cube': (.40, .12)}
    locations = {name: 'table' for name in positions}
    if occupied:
        positions['blue_cube'] = (.30, -.27)
        locations['blue_cube'] = 'zone_a'
    return {'positions': positions, 'locations': locations, 'held_object': ''}


def purple_steps():
    return [{'skill': 'detect_objects'},
            {'skill': 'check_zone', 'zone': 'zone_a'},
            {'skill': 'find_object', 'object': 'purple_cube'},
            {'skill': 'pick', 'object': 'purple_cube'},
            {'skill': 'place', 'object': 'purple_cube', 'zone': 'zone_a'},
            {'skill': 'home'}]


def test_purple_to_empty_zone_a():
    assert validate({'plan': purple_steps()}, state())[3]['object'] == 'purple_cube'


def test_purple_cannot_overwrite_occupied_zone():
    with pytest.raises(ValidationError) as error:
        validate({'plan': purple_steps()}, state(True))
    assert error.value.status == 'ZONE_OCCUPIED'


def test_purple_after_relocating_blocker():
    plan = [{'skill': 'detect_objects'},
            {'skill': 'check_zone', 'zone': 'zone_a'},
            {'skill': 'find_free_position', 'zone': 'buffer'},
            {'skill': 'find_object', 'object': 'blue_cube'},
            {'skill': 'pick', 'object': 'blue_cube'},
            {'skill': 'check_zone', 'zone': 'buffer'},
            {'skill': 'place', 'object': 'blue_cube', 'zone': 'buffer'}] + purple_steps()
    assert len(validate({'plan': plan}, state(True))) == 13


def test_manipulation_without_observation_rejected():
    with pytest.raises(ValidationError) as error:
        validate({'plan': purple_steps()[3:]}, state())
    assert error.value.status == 'INVALID_SEQUENCE'


def test_temporary_slot_requires_camera_checked_space():
    steps = purple_steps()
    steps[1]['zone'] = 'buffer'
    steps[4]['zone'] = 'buffer'
    with pytest.raises(ValidationError) as error:
        validate({'plan': steps}, state())
    assert error.value.status == 'INVALID_SEQUENCE'


def test_manager_retries_rejected_plan_and_displays_observation_skills(capsys):
    from task_manager import TaskManager
    calls = []
    executed = []
    events = []

    class Planner:
        def generate_plan(self, command, world, mapping, feedback=None):
            calls.append(feedback)
            return {'plan': purple_steps()[3:] if len(calls) == 1 else purple_steps()}

    class Executor:
        def execute(self, steps):
            executed.extend(steps)
            events.extend(step["skill"] for step in steps)

    class Task:
        planner = Planner()
        skill_executor = Executor()
        observations = 0

        def world_state(self):
            events.append("state")
            self.observations += 1
            observed = state()
            if self.observations > 1:
                observed['locations']['purple_cube'] = 'zone_a'
                observed['positions']['purple_cube'] = (.30, -.27)
            return observed

    TaskManager.run_command(Task(), 'Đưa khối màu tím vào zone A')
    output = capsys.readouterr().out
    assert len(calls) == 2 and 'INVALID_SEQUENCE' in calls[1]
    assert executed[0]['skill'] == 'detect_objects'
    assert 'detect_objects()' in output
    assert 'check_zone(zone_a)' in output
    assert 'find_object(purple_cube)' in output
    assert 'TASK SUCCESS' in output
    assert events[-1] == 'home'
    assert events[0] == 'detect_objects'
    assert events[-2] == 'state'
