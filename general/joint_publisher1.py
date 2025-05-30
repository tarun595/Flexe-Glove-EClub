import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import serial
import time

class JointPublisherFromSerial(Node):
    def __init__(self):
        super().__init__('joint_state_from_serial')

        # customize this based on your URDF joint name + limits
        self.joint_name = 'middle2_WS'
        self.min_angle = -0.25       # min joint angle in radians
        self.max_angle =  0.7   # max joint angle in radians

        # connect to Arduino (make sure Serial Monitor is CLOSED)
        try:
            self.ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
            time.sleep(2)  # wait for Arduino to reset
        except serial.SerialException:
            self.get_logger().error("Could not open /dev/ttyUSB0. Is it in use?")
            exit(1)

        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)
        self.timer = self.create_timer(0.05, self.timer_callback)

        self.get_logger().info("JointPublisherFromSerial Node Started ✅")

    def timer_callback(self):
        if self.ser.in_waiting > 0:
            try:
                line = self.ser.readline().decode('utf-8').strip()
                pot_val = int(line)

                mapped_angle = self.map_range(pot_val, 0, 1023, self.min_angle, self.max_angle)

                # full joint list
                self.joint_names = [
                    'middle1_KU', 'bottom1_KU-1',
                    'middle2_WS', 'bottom2_WS-1',
                    'middle3_SR', 'bottom3_SR-1',
                    'middle4_SE', 'bottom4_SE-1',
                    'middle5_MA', 'bottom5_MA-1',
                    'base_link_MA-2', 'base_link_SE-2',
                    'base_link_SR-2', 'base_link_WS-2',
                    'base_link_KU-2'
                ]
                positions = [0.0] * len(self.joint_names)

                # just change one joint's value
                idx = self.joint_names.index('middle3_SR')
                positions[idx] = mapped_angle

                msg = JointState()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.name = self.joint_names
                msg.position = positions

                self.joint_pub.publish(msg)
                self.get_logger().info(f"Updated middle3_SR: {mapped_angle:.2f} rad")

            except Exception as e:
                self.get_logger().warn(f"Serial read error: {e}")

    
    def map_range(self, x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

def main(args=None):
    rclpy.init(args=args)
    node = JointPublisherFromSerial()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
