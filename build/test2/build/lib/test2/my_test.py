#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class my_node(Node):
    def __init__(self):
        super().__init__('my_node')
        self.get_logger().info("Hello from Ros2")

def main(args = None):
    rclpy.init(args = args)
    node = Node('my_node')
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()