#include <iostream>

#include <rclcpp/rclcpp.hpp>
#include "laser_publisher_node.hpp"
#include "laser_subscriber_node.hpp"

int main(int argc, char** argv)
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);
  rclcpp::init(argc, argv);

  auto laser_pub_node = std::make_shared<LaserPublisherNode>("sick_lms_pub", "sick_lms_topic", 10);
  laser_pub_node->run();

  auto laser_sub_node = std::make_shared<LaserSubscriberNode>("sick_lms_sub", "sick_lms_topic");
  laser_sub_node->run();

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(laser_pub_node);
  executor.add_node(laser_sub_node);

  executor.spin();
  return 0;
}
