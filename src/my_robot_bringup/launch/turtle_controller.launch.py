from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    ld=LaunchDescription()
    pos_pub_node=Node(
        package="mypkg",
        executable="turtle_controller"
    )
    turtlesim_node=Node(
        package="turtlesim",
        executable="turtlesim_node"
    )
    ld.add_action(turtlesim_node)
    ld.add_action(pos_pub_node)
    return ld