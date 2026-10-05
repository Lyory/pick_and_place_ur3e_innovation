// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur3_llm_control:srv/ExecuteSkill.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__STRUCT_H_
#define UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'skill'
// Member 'object'
// Member 'zone'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecuteSkill in the package ur3_llm_control.
typedef struct ur3_llm_control__srv__ExecuteSkill_Request
{
  rosidl_runtime_c__String skill;
  rosidl_runtime_c__String object;
  rosidl_runtime_c__String zone;
} ur3_llm_control__srv__ExecuteSkill_Request;

// Struct for a sequence of ur3_llm_control__srv__ExecuteSkill_Request.
typedef struct ur3_llm_control__srv__ExecuteSkill_Request__Sequence
{
  ur3_llm_control__srv__ExecuteSkill_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur3_llm_control__srv__ExecuteSkill_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecuteSkill in the package ur3_llm_control.
typedef struct ur3_llm_control__srv__ExecuteSkill_Response
{
  bool success;
  rosidl_runtime_c__String status;
  rosidl_runtime_c__String message;
} ur3_llm_control__srv__ExecuteSkill_Response;

// Struct for a sequence of ur3_llm_control__srv__ExecuteSkill_Response.
typedef struct ur3_llm_control__srv__ExecuteSkill_Response__Sequence
{
  ur3_llm_control__srv__ExecuteSkill_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur3_llm_control__srv__ExecuteSkill_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__STRUCT_H_
