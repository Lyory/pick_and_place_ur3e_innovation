// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur3_llm_control:srv/SetAttachment.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__BUILDER_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur3_llm_control/srv/detail/set_attachment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur3_llm_control
{

namespace srv
{

namespace builder
{

class Init_SetAttachment_Request_object
{
public:
  explicit Init_SetAttachment_Request_object(::ur3_llm_control::srv::SetAttachment_Request & msg)
  : msg_(msg)
  {}
  ::ur3_llm_control::srv::SetAttachment_Request object(::ur3_llm_control::srv::SetAttachment_Request::_object_type arg)
  {
    msg_.object = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur3_llm_control::srv::SetAttachment_Request msg_;
};

class Init_SetAttachment_Request_action
{
public:
  Init_SetAttachment_Request_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetAttachment_Request_object action(::ur3_llm_control::srv::SetAttachment_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return Init_SetAttachment_Request_object(msg_);
  }

private:
  ::ur3_llm_control::srv::SetAttachment_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur3_llm_control::srv::SetAttachment_Request>()
{
  return ur3_llm_control::srv::builder::Init_SetAttachment_Request_action();
}

}  // namespace ur3_llm_control


namespace ur3_llm_control
{

namespace srv
{

namespace builder
{

class Init_SetAttachment_Response_message
{
public:
  explicit Init_SetAttachment_Response_message(::ur3_llm_control::srv::SetAttachment_Response & msg)
  : msg_(msg)
  {}
  ::ur3_llm_control::srv::SetAttachment_Response message(::ur3_llm_control::srv::SetAttachment_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur3_llm_control::srv::SetAttachment_Response msg_;
};

class Init_SetAttachment_Response_success
{
public:
  Init_SetAttachment_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetAttachment_Response_message success(::ur3_llm_control::srv::SetAttachment_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetAttachment_Response_message(msg_);
  }

private:
  ::ur3_llm_control::srv::SetAttachment_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur3_llm_control::srv::SetAttachment_Response>()
{
  return ur3_llm_control::srv::builder::Init_SetAttachment_Response_success();
}

}  // namespace ur3_llm_control

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__BUILDER_HPP_
