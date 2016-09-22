#pragma once

#include <rclcpp/simple_subscriber_node.hpp>
#include <sensor_msgs/msg/laser_scan.h>

using LaserT = sensor_msgs::msg::LaserScan;

class LaserSubscriberNode : public rclcpp::node::SimpleSubscriberNode<LaserT>
{
public:
  LaserSubscriberNode( std::string node_name, std::string topic ):
    SimpleSubscriberNode(std::move(node_name), std::move(topic))
  {
  }

  void callback( LaserT::UniquePtr laser_msg )
  {
    printf("Received fancy laser msg \n");
  }
};
