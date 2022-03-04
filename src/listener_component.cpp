#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <ros2_pybind_pkg/listener_component.hpp>

#include <std_msgs/msg/string.hpp>

#include <pybind11/embed.h>  // everything needed for embedding

#include <string>
namespace py = pybind11;

namespace ros2_pybind_pkg
{
// Create a Listener class that subclasses the generic rclcpp::Node base class.
// The main function below will instantiate the class as a ROS node.
class Listener : public rclcpp::Node
{
public:
  ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC
  explicit Listener(const rclcpp::NodeOptions & options) : Node("listener", options)
  {
    RCLCPP_ERROR(get_logger(), "initialize");
    sub_ = create_subscription<std_msgs::msg::String>(
      "chatter", 1, std::bind(&Listener::chatterCallback, this, std::placeholders::_1));
    py::scoped_interpreter guard{};
    py::print("python initialize");
    // cowsay = py::module::import("cowsay");
  }

  void chatterCallback(const std_msgs::msg::String::SharedPtr msg)
  {
    // RCLCPP_INFO_STREAM(get_logger(), msg->data);
    py::scoped_interpreter guard{};
    // variable not works
    // py::print(msg->data);
    py::print("py print");
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
  // py::module cowsay;
};

}  // namespace ros2_pybind_pkg

RCLCPP_COMPONENTS_REGISTER_NODE(ros2_pybind_pkg::Listener)
