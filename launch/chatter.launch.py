import launch
from launch_ros.actions import Node


def generate_launch_description():
    # talker node

    # listener node
    listener_node = Node(
        package="pybind_demo",
        executable="listener_node",
        output="screen",
        name="listner",
    )

    talker_node = Node(
        package="pybind_demo",
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
