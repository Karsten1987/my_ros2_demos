#include "laser_emulator.hpp"
#include "time.h"

#ifdef _WIN32
	#define M_PI 3.14
#endif

namespace laser_emulator
{
namespace sick
{
using LaserT = sensor_msgs::msg::LaserScan;

LMS141::LMS141( size_t scan_size, size_t noise_rate ):
  scan_size_(scan_size),
  noise_rate_(noise_rate),
  r(),
  engine(r())
{
}

std::unique_ptr<LaserT> LMS141::emulate_scan( )
{
  std::unique_ptr<LaserT> scan(new LaserT());
  scan->header.stamp = rclcpp::Time::now();
  scan->header.frame_id = "laser_frame";

  scan->angle_min = -135.0 * M_PI/180.0;
  scan->angle_max = +135.0 * M_PI/180.0;
  scan->angle_increment = ((scan->angle_min-scan->angle_max)/scan_size_) * M_PI/180.0;

  scan->ranges.resize(scan_size_, 3.0);

  std::uniform_int_distribution<> uniform(0, scan_size_-1);

  for (size_t i=0; i< static_cast<size_t>(scan_size_/noise_rate_); ++i)
  {
    scan->ranges[uniform(engine)] = static_cast<double>(uniform(engine))/1000.0;
  }
  return scan;
}

} // ns sick
} // ns laser_emulator
