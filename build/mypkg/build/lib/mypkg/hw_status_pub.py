#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus 

class HardwareStatuspub(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("Hardware_Status_Pub") # MODIFY NAME
        self.hardware_status_pub=self.create_publisher(HardwareStatus,"hardware_status",10)
        self.timer=self.create_timer(1.0,self.publish_hw_status)
        self.get_logger().info("Hardware Status publisher has Started ")
    def publish_hw_status(self):
        msg=HardwareStatus()
        msg.temperature=30
        msg.are_motors_ready=True
        msg.debug_message="Helo"
        self.hardware_status_pub.publish (msg)
        


def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatuspub() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
