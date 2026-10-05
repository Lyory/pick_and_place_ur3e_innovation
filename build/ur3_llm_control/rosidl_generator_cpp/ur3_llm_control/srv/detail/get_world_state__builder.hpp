// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur3_llm_control:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__BUILDER_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur3_llm_control/srv/detail/get_world_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur3_llm_control
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur3_llm_control::srv::GetWorldState_Request>()
{
  return ::ur3_llm_control::srv::GetWorldState_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace ur3_llm_control


namespace ur3_llm_control
{

namespace srv
{

namespace builder
{

class Init_GetWorldState_Response_camera_ready
{
public:
  explicit Init_GetWorldState_Response_camera_ready(::ur3_llm_control::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  ::ur3_llm_control::srv::GetWorldState_Response camera_ready(::ur3_llm_control::srv::GetWorldState_Response::_camera_ready_type arg)
  {
    msg_.camera_ready = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur3_llm_control::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_y
{
public:
  explicit Init_GetWorldState_Response_y(::ur3_llm_control::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  Init_GetWorldState_Response_camera_ready y(::ur3_llm_control::srv::GetWorldState_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GetWorldState_Response_camera_ready(msg_);
  }

private:
  ::ur3_llm_control::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_x
{
public:
  explicit Init_GetWorldState_Response_x(::ur3_llm_control::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  Init_GetWorldState_Response_y x(::ur3_llm_control::srv::GetWorldState_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetWorldState_Response_y(msg_);
  }

private:
  ::ur3_llm_control::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_held_object
{
public:
  explicit Init_GetWorldState_Response_held_object(::ur3_llm_control::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  Init_GetWorldState_Response_x held_object(::ur3_llm_control::srv::GetWorldState_Response::_held_object_type arg)
  {
    msg_.held_object = std::move(arg);
    return Init_GetWorldState_Response_x(msg_);
  }

private:
  ::ur3_llm_control::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_locations
{
public:
  explicit Init_GetWorldState_Response_locations(::ur3_llm_control::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  Init_GetWorldState_Response_held_object locations(::ur3_llm_control::srv::GetWorldState_Response::_locations_type arg)
  {
    msg_.locations = std::move(arg);
    return Init_GetWorldState_Response_held_object(msg_);
  }

private:
  ::ur3_llm_control::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_objects
{
public:
  Init_GetWorldState_Response_objects()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWorldState_Response_locations objects(::ur3_llm_control::srv::GetWorldState_Response::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return Init_GetWorldState_Response_locations(msg_);
  }

private:
  ::ur3_llm_control::srv::GetWorldState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur3_llm_control::srv::GetWorldState_Response>()
{
  return ur3_llm_control::srv::builder::Init_GetWorldState_Response_objects();
}

}  // namespace ur3_llm_control

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__BUILDER_HPP_
