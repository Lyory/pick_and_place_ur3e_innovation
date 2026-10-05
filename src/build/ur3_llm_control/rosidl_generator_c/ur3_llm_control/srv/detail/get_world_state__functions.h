// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ur3_llm_control:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__FUNCTIONS_H_
#define UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ur3_llm_control/msg/rosidl_generator_c__visibility_control.h"

#include "ur3_llm_control/srv/detail/get_world_state__struct.h"

/// Initialize srv/GetWorldState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ur3_llm_control__srv__GetWorldState_Request
 * )) before or use
 * ur3_llm_control__srv__GetWorldState_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Request__init(ur3_llm_control__srv__GetWorldState_Request * msg);

/// Finalize srv/GetWorldState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Request__fini(ur3_llm_control__srv__GetWorldState_Request * msg);

/// Create srv/GetWorldState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ur3_llm_control__srv__GetWorldState_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
ur3_llm_control__srv__GetWorldState_Request *
ur3_llm_control__srv__GetWorldState_Request__create();

/// Destroy srv/GetWorldState message.
/**
 * It calls
 * ur3_llm_control__srv__GetWorldState_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Request__destroy(ur3_llm_control__srv__GetWorldState_Request * msg);

/// Check for srv/GetWorldState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Request__are_equal(const ur3_llm_control__srv__GetWorldState_Request * lhs, const ur3_llm_control__srv__GetWorldState_Request * rhs);

/// Copy a srv/GetWorldState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Request__copy(
  const ur3_llm_control__srv__GetWorldState_Request * input,
  ur3_llm_control__srv__GetWorldState_Request * output);

/// Initialize array of srv/GetWorldState messages.
/**
 * It allocates the memory for the number of elements and calls
 * ur3_llm_control__srv__GetWorldState_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Request__Sequence__init(ur3_llm_control__srv__GetWorldState_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetWorldState messages.
/**
 * It calls
 * ur3_llm_control__srv__GetWorldState_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Request__Sequence__fini(ur3_llm_control__srv__GetWorldState_Request__Sequence * array);

/// Create array of srv/GetWorldState messages.
/**
 * It allocates the memory for the array and calls
 * ur3_llm_control__srv__GetWorldState_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
ur3_llm_control__srv__GetWorldState_Request__Sequence *
ur3_llm_control__srv__GetWorldState_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetWorldState messages.
/**
 * It calls
 * ur3_llm_control__srv__GetWorldState_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Request__Sequence__destroy(ur3_llm_control__srv__GetWorldState_Request__Sequence * array);

/// Check for srv/GetWorldState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Request__Sequence__are_equal(const ur3_llm_control__srv__GetWorldState_Request__Sequence * lhs, const ur3_llm_control__srv__GetWorldState_Request__Sequence * rhs);

/// Copy an array of srv/GetWorldState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Request__Sequence__copy(
  const ur3_llm_control__srv__GetWorldState_Request__Sequence * input,
  ur3_llm_control__srv__GetWorldState_Request__Sequence * output);

/// Initialize srv/GetWorldState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ur3_llm_control__srv__GetWorldState_Response
 * )) before or use
 * ur3_llm_control__srv__GetWorldState_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Response__init(ur3_llm_control__srv__GetWorldState_Response * msg);

/// Finalize srv/GetWorldState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Response__fini(ur3_llm_control__srv__GetWorldState_Response * msg);

/// Create srv/GetWorldState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ur3_llm_control__srv__GetWorldState_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
ur3_llm_control__srv__GetWorldState_Response *
ur3_llm_control__srv__GetWorldState_Response__create();

/// Destroy srv/GetWorldState message.
/**
 * It calls
 * ur3_llm_control__srv__GetWorldState_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Response__destroy(ur3_llm_control__srv__GetWorldState_Response * msg);

/// Check for srv/GetWorldState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Response__are_equal(const ur3_llm_control__srv__GetWorldState_Response * lhs, const ur3_llm_control__srv__GetWorldState_Response * rhs);

/// Copy a srv/GetWorldState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Response__copy(
  const ur3_llm_control__srv__GetWorldState_Response * input,
  ur3_llm_control__srv__GetWorldState_Response * output);

/// Initialize array of srv/GetWorldState messages.
/**
 * It allocates the memory for the number of elements and calls
 * ur3_llm_control__srv__GetWorldState_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Response__Sequence__init(ur3_llm_control__srv__GetWorldState_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetWorldState messages.
/**
 * It calls
 * ur3_llm_control__srv__GetWorldState_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Response__Sequence__fini(ur3_llm_control__srv__GetWorldState_Response__Sequence * array);

/// Create array of srv/GetWorldState messages.
/**
 * It allocates the memory for the array and calls
 * ur3_llm_control__srv__GetWorldState_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
ur3_llm_control__srv__GetWorldState_Response__Sequence *
ur3_llm_control__srv__GetWorldState_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetWorldState messages.
/**
 * It calls
 * ur3_llm_control__srv__GetWorldState_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
void
ur3_llm_control__srv__GetWorldState_Response__Sequence__destroy(ur3_llm_control__srv__GetWorldState_Response__Sequence * array);

/// Check for srv/GetWorldState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Response__Sequence__are_equal(const ur3_llm_control__srv__GetWorldState_Response__Sequence * lhs, const ur3_llm_control__srv__GetWorldState_Response__Sequence * rhs);

/// Copy an array of srv/GetWorldState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur3_llm_control
bool
ur3_llm_control__srv__GetWorldState_Response__Sequence__copy(
  const ur3_llm_control__srv__GetWorldState_Response__Sequence * input,
  ur3_llm_control__srv__GetWorldState_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__FUNCTIONS_H_
