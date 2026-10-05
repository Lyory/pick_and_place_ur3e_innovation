// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ur3_llm_control:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__TRAITS_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ur3_llm_control/srv/detail/get_world_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ur3_llm_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWorldState_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWorldState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWorldState_Request & msg, bool use_flow_style = false)
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
  const ur3_llm_control::srv::GetWorldState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ur3_llm_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ur3_llm_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const ur3_llm_control::srv::GetWorldState_Request & msg)
{
  return ur3_llm_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ur3_llm_control::srv::GetWorldState_Request>()
{
  return "ur3_llm_control::srv::GetWorldState_Request";
}

template<>
inline const char * name<ur3_llm_control::srv::GetWorldState_Request>()
{
  return "ur3_llm_control/srv/GetWorldState_Request";
}

template<>
struct has_fixed_size<ur3_llm_control::srv::GetWorldState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ur3_llm_control::srv::GetWorldState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ur3_llm_control::srv::GetWorldState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ur3_llm_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWorldState_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: locations
  {
    if (msg.locations.size() == 0) {
      out << "locations: []";
    } else {
      out << "locations: [";
      size_t pending_items = msg.locations.size();
      for (auto item : msg.locations) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: held_object
  {
    out << "held_object: ";
    rosidl_generator_traits::value_to_yaml(msg.held_object, out);
    out << ", ";
  }

  // member: x
  {
    if (msg.x.size() == 0) {
      out << "x: []";
    } else {
      out << "x: [";
      size_t pending_items = msg.x.size();
      for (auto item : msg.x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y
  {
    if (msg.y.size() == 0) {
      out << "y: []";
    } else {
      out << "y: [";
      size_t pending_items = msg.y.size();
      for (auto item : msg.y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: camera_ready
  {
    out << "camera_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_ready, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWorldState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: locations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.locations.size() == 0) {
      out << "locations: []\n";
    } else {
      out << "locations:\n";
      for (auto item : msg.locations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: held_object
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "held_object: ";
    rosidl_generator_traits::value_to_yaml(msg.held_object, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: camera_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_ready, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWorldState_Response & msg, bool use_flow_style = false)
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
  const ur3_llm_control::srv::GetWorldState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ur3_llm_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ur3_llm_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const ur3_llm_control::srv::GetWorldState_Response & msg)
{
  return ur3_llm_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ur3_llm_control::srv::GetWorldState_Response>()
{
  return "ur3_llm_control::srv::GetWorldState_Response";
}

template<>
inline const char * name<ur3_llm_control::srv::GetWorldState_Response>()
{
  return "ur3_llm_control/srv/GetWorldState_Response";
}

template<>
struct has_fixed_size<ur3_llm_control::srv::GetWorldState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ur3_llm_control::srv::GetWorldState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ur3_llm_control::srv::GetWorldState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ur3_llm_control::srv::GetWorldState>()
{
  return "ur3_llm_control::srv::GetWorldState";
}

template<>
inline const char * name<ur3_llm_control::srv::GetWorldState>()
{
  return "ur3_llm_control/srv/GetWorldState";
}

template<>
struct has_fixed_size<ur3_llm_control::srv::GetWorldState>
  : std::integral_constant<
    bool,
    has_fixed_size<ur3_llm_control::srv::GetWorldState_Request>::value &&
    has_fixed_size<ur3_llm_control::srv::GetWorldState_Response>::value
  >
{
};

template<>
struct has_bounded_size<ur3_llm_control::srv::GetWorldState>
  : std::integral_constant<
    bool,
    has_bounded_size<ur3_llm_control::srv::GetWorldState_Request>::value &&
    has_bounded_size<ur3_llm_control::srv::GetWorldState_Response>::value
  >
{
};

template<>
struct is_service<ur3_llm_control::srv::GetWorldState>
  : std::true_type
{
};

template<>
struct is_service_request<ur3_llm_control::srv::GetWorldState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ur3_llm_control::srv::GetWorldState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__TRAITS_HPP_
