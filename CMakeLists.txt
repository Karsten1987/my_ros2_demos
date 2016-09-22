cmake_minimum_required(VERSION 3.5)

project(my_ros2_demos)

if(NOT WIND32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclc REQUIRED)
find_package(rmw REQUIRED)
find_package(rmw_implementation_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)

macro(targets)
  if (NOT target_suffix STREQUAL "")
    get_rclcpp_information("${rmw_implementation}" "rclcpp${target_suffix}")
  endif()

  add_executable(laser_pipeline${target_suffix}
    src/laser_pipeline.cpp
    src/laser_emulator.cpp)
  ament_target_dependencies(laser_pipeline${target_suffix}
    "rclcpp${target_suffix}"
    "rcl${target_suffix}"
    "sensor_msgs")

  install(TARGETS
    laser_pipeline${target_suffix}
    DESTINATION bin)
endmacro()

call_for_each_rmw_implementation(targets GENERATE_DEFAULT)
ament_package()
