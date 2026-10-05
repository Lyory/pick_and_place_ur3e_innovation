// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ur3_llm_control:srv/GetWorldState.idl
// generated code does not contain a copyright notice
#include "ur3_llm_control/srv/detail/get_world_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ur3_llm_control__srv__GetWorldState_Request__init(ur3_llm_control__srv__GetWorldState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
ur3_llm_control__srv__GetWorldState_Request__fini(ur3_llm_control__srv__GetWorldState_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
ur3_llm_control__srv__GetWorldState_Request__are_equal(const ur3_llm_control__srv__GetWorldState_Request * lhs, const ur3_llm_control__srv__GetWorldState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
ur3_llm_control__srv__GetWorldState_Request__copy(
  const ur3_llm_control__srv__GetWorldState_Request * input,
  ur3_llm_control__srv__GetWorldState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

ur3_llm_control__srv__GetWorldState_Request *
ur3_llm_control__srv__GetWorldState_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__GetWorldState_Request * msg = (ur3_llm_control__srv__GetWorldState_Request *)allocator.allocate(sizeof(ur3_llm_control__srv__GetWorldState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur3_llm_control__srv__GetWorldState_Request));
  bool success = ur3_llm_control__srv__GetWorldState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur3_llm_control__srv__GetWorldState_Request__destroy(ur3_llm_control__srv__GetWorldState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur3_llm_control__srv__GetWorldState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur3_llm_control__srv__GetWorldState_Request__Sequence__init(ur3_llm_control__srv__GetWorldState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__GetWorldState_Request * data = NULL;

  if (size) {
    data = (ur3_llm_control__srv__GetWorldState_Request *)allocator.zero_allocate(size, sizeof(ur3_llm_control__srv__GetWorldState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur3_llm_control__srv__GetWorldState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur3_llm_control__srv__GetWorldState_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ur3_llm_control__srv__GetWorldState_Request__Sequence__fini(ur3_llm_control__srv__GetWorldState_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ur3_llm_control__srv__GetWorldState_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ur3_llm_control__srv__GetWorldState_Request__Sequence *
ur3_llm_control__srv__GetWorldState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__GetWorldState_Request__Sequence * array = (ur3_llm_control__srv__GetWorldState_Request__Sequence *)allocator.allocate(sizeof(ur3_llm_control__srv__GetWorldState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur3_llm_control__srv__GetWorldState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur3_llm_control__srv__GetWorldState_Request__Sequence__destroy(ur3_llm_control__srv__GetWorldState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur3_llm_control__srv__GetWorldState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur3_llm_control__srv__GetWorldState_Request__Sequence__are_equal(const ur3_llm_control__srv__GetWorldState_Request__Sequence * lhs, const ur3_llm_control__srv__GetWorldState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur3_llm_control__srv__GetWorldState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur3_llm_control__srv__GetWorldState_Request__Sequence__copy(
  const ur3_llm_control__srv__GetWorldState_Request__Sequence * input,
  ur3_llm_control__srv__GetWorldState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur3_llm_control__srv__GetWorldState_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur3_llm_control__srv__GetWorldState_Request * data =
      (ur3_llm_control__srv__GetWorldState_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur3_llm_control__srv__GetWorldState_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur3_llm_control__srv__GetWorldState_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur3_llm_control__srv__GetWorldState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `objects`
// Member `locations`
// Member `held_object`
#include "rosidl_runtime_c/string_functions.h"
// Member `x`
// Member `y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ur3_llm_control__srv__GetWorldState_Response__init(ur3_llm_control__srv__GetWorldState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // objects
  if (!rosidl_runtime_c__String__Sequence__init(&msg->objects, 0)) {
    ur3_llm_control__srv__GetWorldState_Response__fini(msg);
    return false;
  }
  // locations
  if (!rosidl_runtime_c__String__Sequence__init(&msg->locations, 0)) {
    ur3_llm_control__srv__GetWorldState_Response__fini(msg);
    return false;
  }
  // held_object
  if (!rosidl_runtime_c__String__init(&msg->held_object)) {
    ur3_llm_control__srv__GetWorldState_Response__fini(msg);
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->x, 0)) {
    ur3_llm_control__srv__GetWorldState_Response__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->y, 0)) {
    ur3_llm_control__srv__GetWorldState_Response__fini(msg);
    return false;
  }
  // camera_ready
  return true;
}

void
ur3_llm_control__srv__GetWorldState_Response__fini(ur3_llm_control__srv__GetWorldState_Response * msg)
{
  if (!msg) {
    return;
  }
  // objects
  rosidl_runtime_c__String__Sequence__fini(&msg->objects);
  // locations
  rosidl_runtime_c__String__Sequence__fini(&msg->locations);
  // held_object
  rosidl_runtime_c__String__fini(&msg->held_object);
  // x
  rosidl_runtime_c__double__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__double__Sequence__fini(&msg->y);
  // camera_ready
}

bool
ur3_llm_control__srv__GetWorldState_Response__are_equal(const ur3_llm_control__srv__GetWorldState_Response * lhs, const ur3_llm_control__srv__GetWorldState_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // objects
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->objects), &(rhs->objects)))
  {
    return false;
  }
  // locations
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->locations), &(rhs->locations)))
  {
    return false;
  }
  // held_object
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->held_object), &(rhs->held_object)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // camera_ready
  if (lhs->camera_ready != rhs->camera_ready) {
    return false;
  }
  return true;
}

bool
ur3_llm_control__srv__GetWorldState_Response__copy(
  const ur3_llm_control__srv__GetWorldState_Response * input,
  ur3_llm_control__srv__GetWorldState_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // objects
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->objects), &(output->objects)))
  {
    return false;
  }
  // locations
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->locations), &(output->locations)))
  {
    return false;
  }
  // held_object
  if (!rosidl_runtime_c__String__copy(
      &(input->held_object), &(output->held_object)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // camera_ready
  output->camera_ready = input->camera_ready;
  return true;
}

ur3_llm_control__srv__GetWorldState_Response *
ur3_llm_control__srv__GetWorldState_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__GetWorldState_Response * msg = (ur3_llm_control__srv__GetWorldState_Response *)allocator.allocate(sizeof(ur3_llm_control__srv__GetWorldState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur3_llm_control__srv__GetWorldState_Response));
  bool success = ur3_llm_control__srv__GetWorldState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur3_llm_control__srv__GetWorldState_Response__destroy(ur3_llm_control__srv__GetWorldState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur3_llm_control__srv__GetWorldState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur3_llm_control__srv__GetWorldState_Response__Sequence__init(ur3_llm_control__srv__GetWorldState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__GetWorldState_Response * data = NULL;

  if (size) {
    data = (ur3_llm_control__srv__GetWorldState_Response *)allocator.zero_allocate(size, sizeof(ur3_llm_control__srv__GetWorldState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur3_llm_control__srv__GetWorldState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur3_llm_control__srv__GetWorldState_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ur3_llm_control__srv__GetWorldState_Response__Sequence__fini(ur3_llm_control__srv__GetWorldState_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ur3_llm_control__srv__GetWorldState_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ur3_llm_control__srv__GetWorldState_Response__Sequence *
ur3_llm_control__srv__GetWorldState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__GetWorldState_Response__Sequence * array = (ur3_llm_control__srv__GetWorldState_Response__Sequence *)allocator.allocate(sizeof(ur3_llm_control__srv__GetWorldState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur3_llm_control__srv__GetWorldState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur3_llm_control__srv__GetWorldState_Response__Sequence__destroy(ur3_llm_control__srv__GetWorldState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur3_llm_control__srv__GetWorldState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur3_llm_control__srv__GetWorldState_Response__Sequence__are_equal(const ur3_llm_control__srv__GetWorldState_Response__Sequence * lhs, const ur3_llm_control__srv__GetWorldState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur3_llm_control__srv__GetWorldState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur3_llm_control__srv__GetWorldState_Response__Sequence__copy(
  const ur3_llm_control__srv__GetWorldState_Response__Sequence * input,
  ur3_llm_control__srv__GetWorldState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur3_llm_control__srv__GetWorldState_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur3_llm_control__srv__GetWorldState_Response * data =
      (ur3_llm_control__srv__GetWorldState_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur3_llm_control__srv__GetWorldState_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur3_llm_control__srv__GetWorldState_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur3_llm_control__srv__GetWorldState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
