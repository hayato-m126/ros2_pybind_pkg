#include <pybind_demo/listener_component.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include <iostream>
#include <memory>

namespace pybind_demo
{
// Create a Listener class that subclasses the generic rclcpp::Node base class.
// The main function below will instantiate the class as a ROS node.

ListenerComponent::ListenerComponent(const rclcpp::NodeOptions & options)
: Node("listener_component", options)
{
  sub_ = this->create_subscription<std_msgs::msg::String>(
    "chatter", 1, std::bind(&ListenerComponent::chatterCallback, this, std::placeholders::_1));
  // py::scoped_interpreter guard{};
  // py::print("python initialize");
  // cowsay = py::module::import("cowsay");
}

void ListenerComponent::chatterCallback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO_STREAM(get_logger(), msg->data);
  // py::scoped_interpreter guard{};
  // variable not works
  // py::print(msg->data);
  // py::print("py print");
}
// py::module cowsay;
}  // namespace pybind_demo

RCLCPP_COMPONENTS_REGISTER_NODE(pybind_demo::ListenerComponent)
