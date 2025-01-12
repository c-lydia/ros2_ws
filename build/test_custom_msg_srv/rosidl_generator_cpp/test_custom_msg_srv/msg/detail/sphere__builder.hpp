// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_msg_srv:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG_SRV__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define TEST_CUSTOM_MSG_SRV__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_msg_srv/msg/detail/sphere__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_msg_srv
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::test_custom_msg_srv::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::test_custom_msg_srv::msg::Sphere radius(::test_custom_msg_srv::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_msg_srv::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::test_custom_msg_srv::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::test_custom_msg_srv::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_msg_srv::msg::Sphere>()
{
  return test_custom_msg_srv::msg::builder::Init_Sphere_center();
}

}  // namespace test_custom_msg_srv

#endif  // TEST_CUSTOM_MSG_SRV__MSG__DETAIL__SPHERE__BUILDER_HPP_
