// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ur3_llm_control:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__STRUCT_HPP_
#define UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ur3_llm_control__srv__GetWorldState_Request __attribute__((deprecated))
#else
# define DEPRECATED__ur3_llm_control__srv__GetWorldState_Request __declspec(deprecated)
#endif

namespace ur3_llm_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWorldState_Request_
{
  using Type = GetWorldState_Request_<ContainerAllocator>;

  explicit GetWorldState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetWorldState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ur3_llm_control__srv__GetWorldState_Request
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ur3_llm_control__srv__GetWorldState_Request
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWorldState_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWorldState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWorldState_Request_

// alias to use template instance with default allocator
using GetWorldState_Request =
  ur3_llm_control::srv::GetWorldState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ur3_llm_control


#ifndef _WIN32
# define DEPRECATED__ur3_llm_control__srv__GetWorldState_Response __attribute__((deprecated))
#else
# define DEPRECATED__ur3_llm_control__srv__GetWorldState_Response __declspec(deprecated)
#endif

namespace ur3_llm_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWorldState_Response_
{
  using Type = GetWorldState_Response_<ContainerAllocator>;

  explicit GetWorldState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->held_object = "";
      this->camera_ready = false;
    }
  }

  explicit GetWorldState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : held_object(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->held_object = "";
      this->camera_ready = false;
    }
  }

  // field types and members
  using _objects_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _objects_type objects;
  using _locations_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _locations_type locations;
  using _held_object_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _held_object_type held_object;
  using _x_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _x_type x;
  using _y_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _y_type y;
  using _camera_ready_type =
    bool;
  _camera_ready_type camera_ready;

  // setters for named parameter idiom
  Type & set__objects(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }
  Type & set__locations(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->locations = _arg;
    return *this;
  }
  Type & set__held_object(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->held_object = _arg;
    return *this;
  }
  Type & set__x(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__camera_ready(
    const bool & _arg)
  {
    this->camera_ready = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ur3_llm_control__srv__GetWorldState_Response
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ur3_llm_control__srv__GetWorldState_Response
    std::shared_ptr<ur3_llm_control::srv::GetWorldState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWorldState_Response_ & other) const
  {
    if (this->objects != other.objects) {
      return false;
    }
    if (this->locations != other.locations) {
      return false;
    }
    if (this->held_object != other.held_object) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->camera_ready != other.camera_ready) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWorldState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWorldState_Response_

// alias to use template instance with default allocator
using GetWorldState_Response =
  ur3_llm_control::srv::GetWorldState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ur3_llm_control

namespace ur3_llm_control
{

namespace srv
{

struct GetWorldState
{
  using Request = ur3_llm_control::srv::GetWorldState_Request;
  using Response = ur3_llm_control::srv::GetWorldState_Response;
};

}  // namespace srv

}  // namespace ur3_llm_control

#endif  // UR3_LLM_CONTROL__SRV__DETAIL__GET_WORLD_STATE__STRUCT_HPP_
