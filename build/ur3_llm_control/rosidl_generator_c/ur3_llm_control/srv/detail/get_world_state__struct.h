// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur3_llm_control:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__STRUCT_H_
#define UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetWorldState in the package ur3_llm_control.
typedef struct ur3_llm_control__srv__GetWorldState_Request
{
  uint8_t structure_needs_at_least_one_member;
} ur3_llm_control__srv__GetWorldState_Request;

// Struct for a sequence of ur3_llm_control__srv__GetWorldState_Request.
typedef struct ur3_llm_control__srv__GetWorldState_Request__Sequence
{
  ur3_llm_control__srv__GetWorldState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur3_llm_control__srv__GetWorldState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'objects'
// Member 'locations'
// Member 'held_object'
#include "rosidl_runtime_c/string.h"
// Member 'x'
// Member 'y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetWorldState in the package ur3_llm_control.
typedef struct ur3_llm_control__srv__GetWorldState_Response
{
  rosidl_runtime_c__String__Sequence objects;
  rosidl_runtime_c__String__Sequence locations;
  rosidl_runtime_c__String held_object;
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
  bool camera_ready;
} ur3_llm_control__srv__GetWorldState_Response;

// Struct for a sequence of ur3_llm_control__srv__GetWorldState_Response.
typedef struct ur3_llm_control__srv__GetWorldState_Response__Sequence
{
  ur3_llm_control__srv__GetWorldState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur3_llm_control__srv__GetWorldState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__STRUCT_H_
