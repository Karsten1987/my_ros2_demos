#pragma once

#include <random>
#include <cmath>

#include <sensor_msgs/msg/laser_scan.hpp>

namespace laser_emulator
{
namespace sick
{

class LMS141
{
public:
  LMS141( size_t scan_size, size_t noise_rate );

  std::unique_ptr<sensor_msgs::msg::LaserScan> emulate_scan( );

private:
  size_t scan_size_;
  size_t noise_rate_;

  std::random_device r;
  std::mt19937 engine;
};

} // ns sick
} // ns laser_emulator
