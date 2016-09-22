#pragma once

#include <rclcpp/simple_publisher_node.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

#include "laser_emulator.hpp"

using LaserT = sensor_msgs::msg::LaserScan;

class LaserPublisherNode : public rclcpp::node::SimplePublisherNode<LaserT>
{
public:
  LaserPublisherNode( std::string node_name, std::string topic, size_t frequency ):
    SimplePublisherNode(std::move(node_name), std::move(topic), std::move(frequency)),
    lms_(1082, 10)
  {}

  void publish( )
  {
    std::unique_ptr<LaserT> msg = lms_.emulate_scan();
    pub_->publish(msg);
    printf("Publishing fancy laser msg\n");
  }

private:
  laser_emulator::sick::LMS141 lms_;
};
