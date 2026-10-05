// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ur3_llm_control:srv/SetAttachment.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__STRUCT_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ur3_llm_control__srv__SetAttachment_Request __attribute__((deprecated))
#else
# define DEPRECATED__ur3_llm_control__srv__SetAttachment_Request __declspec(deprecated)
#endif

namespace ur3_llm_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetAttachment_Request_
{
  using Type = SetAttachment_Request_<ContainerAllocator>;

  explicit SetAttachment_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action = "";
      this->object = "";
    }
  }

  explicit SetAttachment_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action(_alloc),
    object(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action = "";
      this->object = "";
    }
  }

  // field types and members
  using _action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_type action;
  using _object_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_type object;

  // setters for named parameter idiom
  Type & set__action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action = _arg;
    return *this;
  }
  Type & set__object(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ur3_llm_control__srv__SetAttachment_Request
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ur3_llm_control__srv__SetAttachment_Request
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetAttachment_Request_ & other) const
  {
    if (this->action != other.action) {
      return false;
    }
    if (this->object != other.object) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetAttachment_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetAttachment_Request_

// alias to use template instance with default allocator
using SetAttachment_Request =
  ur3_llm_control::srv::SetAttachment_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ur3_llm_control


#ifndef _WIN32
# define DEPRECATED__ur3_llm_control__srv__SetAttachment_Response __attribute__((deprecated))
#else
# define DEPRECATED__ur3_llm_control__srv__SetAttachment_Response __declspec(deprecated)
#endif

namespace ur3_llm_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetAttachment_Response_
{
  using Type = SetAttachment_Response_<ContainerAllocator>;

  explicit SetAttachment_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetAttachment_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ur3_llm_control__srv__SetAttachment_Response
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ur3_llm_control__srv__SetAttachment_Response
    std::shared_ptr<ur3_llm_control::srv::SetAttachment_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetAttachment_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetAttachment_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetAttachment_Response_

// alias to use template instance with default allocator
using SetAttachment_Response =
  ur3_llm_control::srv::SetAttachment_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ur3_llm_control

namespace ur3_llm_control
{

namespace srv
{

struct SetAttachment
{
  using Request = ur3_llm_control::srv::SetAttachment_Request;
  using Response = ur3_llm_control::srv::SetAttachment_Response;
};

}  // namespace srv

}  // namespace ur3_llm_control

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__SET_ATTACHMENT__STRUCT_HPP_
