// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur3_llm_control:srv/SetAttachment.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__STRUCT_H_
#define UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'action'
// Member 'object'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetAttachment in the package ur3_llm_control.
typedef struct ur3_llm_control__srv__SetAttachment_Request
{
  rosidl_runtime_c__String action;
  rosidl_runtime_c__String object;
} ur3_llm_control__srv__SetAttachment_Request;

// Struct for a sequence of ur3_llm_control__srv__SetAttachment_Request.
typedef struct ur3_llm_control__srv__SetAttachment_Request__Sequence
{
  ur3_llm_control__srv__SetAttachment_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur3_llm_control__srv__SetAttachment_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetAttachment in the package ur3_llm_control.
typedef struct ur3_llm_control__srv__SetAttachment_Response
{
  bool success;
  rosidl_runtime_c__String message;
} ur3_llm_control__srv__SetAttachment_Response;

// Struct for a sequence of ur3_llm_control__srv__SetAttachment_Response.
typedef struct ur3_llm_control__srv__SetAttachment_Response__Sequence
{
  ur3_llm_control__srv__SetAttachment_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur3_llm_control__srv__SetAttachment_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__STRUCT_H_
