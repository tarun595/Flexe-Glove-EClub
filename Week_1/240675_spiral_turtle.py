#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class SpiralTurtle(Node):
    def __init__(self):
        super().__init__('spiral_turtle')
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.move_in_spiral)
        self.linear_velocity = 0.0
        self.angular_velocity = 1.0  # constant turn speed

    def move_in_spiral(self):
        self.linear_velocity += 0.01  # increase speed slowly

        twist = Twist()
        twist.linear.x = self.linear_velocity
        twist.angular.z = self.angular_velocity

        self.publisher_.publish(twist)
        self.get_logger().info(f'Spiral -> linear: {twist.linear.x:.2f}, angular: {twist.angular.z:.2f}')

def main(args=None):
    rclpy.init(args=args)
    node = SpiralTurtle()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
