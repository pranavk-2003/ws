from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="my_cpp_pkg", 
            executable="rpm_pub",
            name="rpm_pub_node",
            parameters=[
                {"rpm_val": 500.0}
            ]
        ),
        Node(
            package="my_cpp_pkg", 
            executable="speed_pub",
            name="speed_pub_node",
            parameters=[
                {"wheel_radius": 100/10.0}
            ]
        ),
        ExecuteProcess(
            cmd=['ros2', 'topic', 'echo','/speed_p'],
            output='screen'
        )
    ])