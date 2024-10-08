#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
class Mynode(Node):
    def __init__(self):
        super().__init__("Mynode")   
        self.create_timer(1.0,self.timer)
    def timer(self):
        self.get_logger().info("Hello")
def main(args=None):
    rclpy.init(args=args)
    node =Mynode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=='__main__':
    main()