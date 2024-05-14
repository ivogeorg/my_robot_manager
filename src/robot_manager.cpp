#include "my_robot_manager/robot_manager.h"

void RobotManager::print_specifications() {
  ROS_INFO("Robot name: %s", robot_name.c_str());
  ROS_INFO("Robot model: %s", robot_model.c_str());
  ROS_INFO("Robot battery capacity (kWh): %f", battery_capacity_kwh);
  ROS_INFO("Robot total operation hours: %d", total_operation_hours);
}