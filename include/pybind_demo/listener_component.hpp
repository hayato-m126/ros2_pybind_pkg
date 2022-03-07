// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PYBIND__LISTENER_COMPONENT_HPP_
#define PYBIND__LISTENER_COMPONENT_HPP_

#include "pybind_demo/visiblity_control.hpp"

#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>

#include <string>

namespace pybind_demo
{
class ListenerComponent : public rclcpp::Node
{
public:
  COMPOSITION_PUBLIC
  explicit ListenerComponent(const rclcpp::NodeOptions & options);

  void chatterCallback(const std_msgs::msg::String::SharedPtr msg);

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};
}  // namespace pybind_demo

#endif  // PYBIND_LISTENER_COMPONENT_HPP_
