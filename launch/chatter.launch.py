import launch
from launch_ros.actions import Node


def generate_launch_description():
    # talker node

    # listener node
    listener_node = Node(
        package="ros2_pybind_pkg",
        executable="listener_node",
        output="screen",
        name="listner",
    )

    talker_node = Node(
        package="ros2_pybind_pkg",
        executable="talker.py",
        output="screen",
        name="talker",
    )

    return launch.LaunchDescription(
        [
            listener_node,
            talker_node,
        ]
    )
