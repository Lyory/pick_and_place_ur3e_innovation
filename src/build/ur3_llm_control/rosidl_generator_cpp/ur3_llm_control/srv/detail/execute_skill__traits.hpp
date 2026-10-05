// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ur3_llm_control:srv/ExecuteSkill.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__TRAITS_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ur3_llm_control/srv/detail/execute_skill__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ur3_llm_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecuteSkill_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: skill
  {
    out << "skill: ";
    rosidl_generator_traits::value_to_yaml(msg.skill, out);
    out << ", ";
  }

  // member: object
  {
    out << "object: ";
    rosidl_generator_traits::value_to_yaml(msg.object, out);
    out << ", ";
  }

  // member: zone
  {
    out << "zone: ";
    rosidl_generator_traits::value_to_yaml(msg.zone, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteSkill_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: skill
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "skill: ";
    rosidl_generator_traits::value_to_yaml(msg.skill, out);
    out << "\n";
  }

  // member: object
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object: ";
    rosidl_generator_traits::value_to_yaml(msg.object, out);
    out << "\n";
  }

  // member: zone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone: ";
    rosidl_generator_traits::value_to_yaml(msg.zone, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteSkill_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ur3_llm_control

namespace rosidl_generator_traits
{

[[deprecated("use ur3_llm_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ur3_llm_control::srv::ExecuteSkill_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ur3_llm_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ur3_llm_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const ur3_llm_control::srv::ExecuteSkill_Request & msg)
{
  return ur3_llm_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ur3_llm_control::srv::ExecuteSkill_Request>()
{
  return "ur3_llm_control::srv::ExecuteSkill_Request";
}

template<>
inline const char * name<ur3_llm_control::srv::ExecuteSkill_Request>()
{
  return "ur3_llm_control/srv/ExecuteSkill_Request";
}

template<>
struct has_fixed_size<ur3_llm_control::srv::ExecuteSkill_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ur3_llm_control::srv::ExecuteSkill_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ur3_llm_control::srv::ExecuteSkill_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ur3_llm_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecuteSkill_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteSkill_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteSkill_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ur3_llm_control

namespace rosidl_generator_traits
{

[[deprecated("use ur3_llm_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ur3_llm_control::srv::ExecuteSkill_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ur3_llm_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ur3_llm_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const ur3_llm_control::srv::ExecuteSkill_Response & msg)
{
  return ur3_llm_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ur3_llm_control::srv::ExecuteSkill_Response>()
{
  return "ur3_llm_control::srv::ExecuteSkill_Response";
}

template<>
inline const char * name<ur3_llm_control::srv::ExecuteSkill_Response>()
{
  return "ur3_llm_control/srv/ExecuteSkill_Response";
}

template<>
struct has_fixed_size<ur3_llm_control::srv::ExecuteSkill_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ur3_llm_control::srv::ExecuteSkill_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ur3_llm_control::srv::ExecuteSkill_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ur3_llm_control::srv::ExecuteSkill>()
{
  return "ur3_llm_control::srv::ExecuteSkill";
}

template<>
inline const char * name<ur3_llm_control::srv::ExecuteSkill>()
{
  return "ur3_llm_control/srv/ExecuteSkill";
}

template<>
struct has_fixed_size<ur3_llm_control::srv::ExecuteSkill>
  : std::integral_constant<
    bool,
    has_fixed_size<ur3_llm_control::srv::ExecuteSkill_Request>::value &&
    has_fixed_size<ur3_llm_control::srv::ExecuteSkill_Response>::value
  >
{
};

template<>
struct has_bounded_size<ur3_llm_control::srv::ExecuteSkill>
  : std::integral_constant<
    bool,
    has_bounded_size<ur3_llm_control::srv::ExecuteSkill_Request>::value &&
    has_bounded_size<ur3_llm_control::srv::ExecuteSkill_Response>::value
  >
{
};

template<>
struct is_service<ur3_llm_control::srv::ExecuteSkill>
  : std::true_type
{
};

template<>
struct is_service_request<ur3_llm_control::srv::ExecuteSkill_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ur3_llm_control::srv::ExecuteSkill_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__EXECUTE_SKILL__TRAITS_HPP_
