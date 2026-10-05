// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur3_llm_control:srv/ExecuteSkill.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__BUILDER_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur3_llm_control/srv/detail/execute_skill__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur3_llm_control
{

namespace srv
{

namespace builder
{

class Init_ExecuteSkill_Request_zone
{
public:
  explicit Init_ExecuteSkill_Request_zone(::ur3_llm_control::srv::ExecuteSkill_Request & msg)
  : msg_(msg)
  {}
  ::ur3_llm_control::srv::ExecuteSkill_Request zone(::ur3_llm_control::srv::ExecuteSkill_Request::_zone_type arg)
  {
    msg_.zone = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur3_llm_control::srv::ExecuteSkill_Request msg_;
};

class Init_ExecuteSkill_Request_object
{
public:
  explicit Init_ExecuteSkill_Request_object(::ur3_llm_control::srv::ExecuteSkill_Request & msg)
  : msg_(msg)
  {}
  Init_ExecuteSkill_Request_zone object(::ur3_llm_control::srv::ExecuteSkill_Request::_object_type arg)
  {
    msg_.object = std::move(arg);
    return Init_ExecuteSkill_Request_zone(msg_);
  }

private:
  ::ur3_llm_control::srv::ExecuteSkill_Request msg_;
};

class Init_ExecuteSkill_Request_skill
{
public:
  Init_ExecuteSkill_Request_skill()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteSkill_Request_object skill(::ur3_llm_control::srv::ExecuteSkill_Request::_skill_type arg)
  {
    msg_.skill = std::move(arg);
    return Init_ExecuteSkill_Request_object(msg_);
  }

private:
  ::ur3_llm_control::srv::ExecuteSkill_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur3_llm_control::srv::ExecuteSkill_Request>()
{
  return ur3_llm_control::srv::builder::Init_ExecuteSkill_Request_skill();
}

}  // namespace ur3_llm_control


namespace ur3_llm_control
{

namespace srv
{

namespace builder
{

class Init_ExecuteSkill_Response_message
{
public:
  explicit Init_ExecuteSkill_Response_message(::ur3_llm_control::srv::ExecuteSkill_Response & msg)
  : msg_(msg)
  {}
  ::ur3_llm_control::srv::ExecuteSkill_Response message(::ur3_llm_control::srv::ExecuteSkill_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur3_llm_control::srv::ExecuteSkill_Response msg_;
};

class Init_ExecuteSkill_Response_status
{
public:
  explicit Init_ExecuteSkill_Response_status(::ur3_llm_control::srv::ExecuteSkill_Response & msg)
  : msg_(msg)
  {}
  Init_ExecuteSkill_Response_message status(::ur3_llm_control::srv::ExecuteSkill_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteSkill_Response_message(msg_);
  }

private:
  ::ur3_llm_control::srv::ExecuteSkill_Response msg_;
};

class Init_ExecuteSkill_Response_success
{
public:
  Init_ExecuteSkill_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteSkill_Response_status success(::ur3_llm_control::srv::ExecuteSkill_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteSkill_Response_status(msg_);
  }

private:
  ::ur3_llm_control::srv::ExecuteSkill_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur3_llm_control::srv::ExecuteSkill_Response>()
{
  return ur3_llm_control::srv::builder::Init_ExecuteSkill_Response_success();
}

}  // namespace ur3_llm_control

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__BUILDER_HPP_
