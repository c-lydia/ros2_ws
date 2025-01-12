// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_msg_srv:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG_SRV__MSG__DETAIL__NUM__BUILDER_HPP_
#define TEST_CUSTOM_MSG_SRV__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_msg_srv/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_msg_srv
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::test_custom_msg_srv::msg::Num num(::test_custom_msg_srv::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_msg_srv::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_msg_srv::msg::Num>()
{
  return test_custom_msg_srv::msg::builder::Init_Num_num();
}

}  // namespace test_custom_msg_srv

#endif  // TEST_CUSTOM_MSG_SRV__MSG__DETAIL__NUM__BUILDER_HPP_
