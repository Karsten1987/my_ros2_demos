#pragma once

#include <chrono>

#include <builtin_interfaces/msg/time.hpp>

namespace rclcpp
{

struct Time
{
  static builtin_interfaces::msg::Time now( )
  {
    builtin_interfaces::msg::Time time;
    std::chrono::nanoseconds now = std::chrono::high_resolution_clock::now().time_since_epoch();
    if (now > std::chrono::nanoseconds(0))
    {
      time.sec = static_cast<builtin_interfaces::msg::Time::_sec_type>(now.count() / 1000000000);
      time.nanosec = now.count() % 1000000000;
    }
    return time;
  }

  //friend std::ostream& operator<<( std::ostream& os, const Time& time );
};

//std::ostream& operator<<( std::ostream& os, const Time& time )
//{
//  os << time.sec << " seconds, " << time.nanosec << " nanoseconds";
//  return os;
//}

} //namespace rclcpp
