// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ur3_llm_control:srv/SetAttachment.idl
// generated code does not contain a copyright notice
#include "ur3_llm_control/srv/detail/set_attachment__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `object`
#include "rosidl_runtime_c/string_functions.h"

bool
ur3_llm_control__srv__SetAttachment_Request__init(ur3_llm_control__srv__SetAttachment_Request * msg)
{
  if (!msg) {
    return false;
  }
  // object
  if (!rosidl_runtime_c__String__init(&msg->object)) {
    ur3_llm_control__srv__SetAttachment_Request__fini(msg);
    return false;
  }
  // attach
  // set_pose
  // x
  // y
  // z
  return true;
}

void
ur3_llm_control__srv__SetAttachment_Request__fini(ur3_llm_control__srv__SetAttachment_Request * msg)
{
  if (!msg) {
    return;
  }
  // object
  rosidl_runtime_c__String__fini(&msg->object);
  // attach
  // set_pose
  // x
  // y
  // z
}

bool
ur3_llm_control__srv__SetAttachment_Request__are_equal(const ur3_llm_control__srv__SetAttachment_Request * lhs, const ur3_llm_control__srv__SetAttachment_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // object
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object), &(rhs->object)))
  {
    return false;
  }
  // attach
  if (lhs->attach != rhs->attach) {
    return false;
  }
  // set_pose
  if (lhs->set_pose != rhs->set_pose) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
ur3_llm_control__srv__SetAttachment_Request__copy(
  const ur3_llm_control__srv__SetAttachment_Request * input,
  ur3_llm_control__srv__SetAttachment_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // object
  if (!rosidl_runtime_c__String__copy(
      &(input->object), &(output->object)))
  {
    return false;
  }
  // attach
  output->attach = input->attach;
  // set_pose
  output->set_pose = input->set_pose;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

ur3_llm_control__srv__SetAttachment_Request *
ur3_llm_control__srv__SetAttachment_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__SetAttachment_Request * msg = (ur3_llm_control__srv__SetAttachment_Request *)allocator.allocate(sizeof(ur3_llm_control__srv__SetAttachment_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur3_llm_control__srv__SetAttachment_Request));
  bool success = ur3_llm_control__srv__SetAttachment_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur3_llm_control__srv__SetAttachment_Request__destroy(ur3_llm_control__srv__SetAttachment_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur3_llm_control__srv__SetAttachment_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur3_llm_control__srv__SetAttachment_Request__Sequence__init(ur3_llm_control__srv__SetAttachment_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__SetAttachment_Request * data = NULL;

  if (size) {
    data = (ur3_llm_control__srv__SetAttachment_Request *)allocator.zero_allocate(size, sizeof(ur3_llm_control__srv__SetAttachment_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur3_llm_control__srv__SetAttachment_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur3_llm_control__srv__SetAttachment_Request__fini(&data[i - 1]);
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
ur3_llm_control__srv__SetAttachment_Request__Sequence__fini(ur3_llm_control__srv__SetAttachment_Request__Sequence * array)
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
      ur3_llm_control__srv__SetAttachment_Request__fini(&array->data[i]);
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

ur3_llm_control__srv__SetAttachment_Request__Sequence *
ur3_llm_control__srv__SetAttachment_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__SetAttachment_Request__Sequence * array = (ur3_llm_control__srv__SetAttachment_Request__Sequence *)allocator.allocate(sizeof(ur3_llm_control__srv__SetAttachment_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur3_llm_control__srv__SetAttachment_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur3_llm_control__srv__SetAttachment_Request__Sequence__destroy(ur3_llm_control__srv__SetAttachment_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur3_llm_control__srv__SetAttachment_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur3_llm_control__srv__SetAttachment_Request__Sequence__are_equal(const ur3_llm_control__srv__SetAttachment_Request__Sequence * lhs, const ur3_llm_control__srv__SetAttachment_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur3_llm_control__srv__SetAttachment_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur3_llm_control__srv__SetAttachment_Request__Sequence__copy(
  const ur3_llm_control__srv__SetAttachment_Request__Sequence * input,
  ur3_llm_control__srv__SetAttachment_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur3_llm_control__srv__SetAttachment_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur3_llm_control__srv__SetAttachment_Request * data =
      (ur3_llm_control__srv__SetAttachment_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur3_llm_control__srv__SetAttachment_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur3_llm_control__srv__SetAttachment_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur3_llm_control__srv__SetAttachment_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
ur3_llm_control__srv__SetAttachment_Response__init(ur3_llm_control__srv__SetAttachment_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    ur3_llm_control__srv__SetAttachment_Response__fini(msg);
    return false;
  }
  return true;
}

void
ur3_llm_control__srv__SetAttachment_Response__fini(ur3_llm_control__srv__SetAttachment_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
ur3_llm_control__srv__SetAttachment_Response__are_equal(const ur3_llm_control__srv__SetAttachment_Response * lhs, const ur3_llm_control__srv__SetAttachment_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
ur3_llm_control__srv__SetAttachment_Response__copy(
  const ur3_llm_control__srv__SetAttachment_Response * input,
  ur3_llm_control__srv__SetAttachment_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

ur3_llm_control__srv__SetAttachment_Response *
ur3_llm_control__srv__SetAttachment_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__SetAttachment_Response * msg = (ur3_llm_control__srv__SetAttachment_Response *)allocator.allocate(sizeof(ur3_llm_control__srv__SetAttachment_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur3_llm_control__srv__SetAttachment_Response));
  bool success = ur3_llm_control__srv__SetAttachment_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur3_llm_control__srv__SetAttachment_Response__destroy(ur3_llm_control__srv__SetAttachment_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur3_llm_control__srv__SetAttachment_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur3_llm_control__srv__SetAttachment_Response__Sequence__init(ur3_llm_control__srv__SetAttachment_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__SetAttachment_Response * data = NULL;

  if (size) {
    data = (ur3_llm_control__srv__SetAttachment_Response *)allocator.zero_allocate(size, sizeof(ur3_llm_control__srv__SetAttachment_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur3_llm_control__srv__SetAttachment_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur3_llm_control__srv__SetAttachment_Response__fini(&data[i - 1]);
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
ur3_llm_control__srv__SetAttachment_Response__Sequence__fini(ur3_llm_control__srv__SetAttachment_Response__Sequence * array)
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
      ur3_llm_control__srv__SetAttachment_Response__fini(&array->data[i]);
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

ur3_llm_control__srv__SetAttachment_Response__Sequence *
ur3_llm_control__srv__SetAttachment_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur3_llm_control__srv__SetAttachment_Response__Sequence * array = (ur3_llm_control__srv__SetAttachment_Response__Sequence *)allocator.allocate(sizeof(ur3_llm_control__srv__SetAttachment_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur3_llm_control__srv__SetAttachment_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur3_llm_control__srv__SetAttachment_Response__Sequence__destroy(ur3_llm_control__srv__SetAttachment_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur3_llm_control__srv__SetAttachment_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur3_llm_control__srv__SetAttachment_Response__Sequence__are_equal(const ur3_llm_control__srv__SetAttachment_Response__Sequence * lhs, const ur3_llm_control__srv__SetAttachment_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur3_llm_control__srv__SetAttachment_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur3_llm_control__srv__SetAttachment_Response__Sequence__copy(
  const ur3_llm_control__srv__SetAttachment_Response__Sequence * input,
  ur3_llm_control__srv__SetAttachment_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur3_llm_control__srv__SetAttachment_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur3_llm_control__srv__SetAttachment_Response * data =
      (ur3_llm_control__srv__SetAttachment_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur3_llm_control__srv__SetAttachment_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur3_llm_control__srv__SetAttachment_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur3_llm_control__srv__SetAttachment_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
