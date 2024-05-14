#include "my_robot_manager/robot_manager.h"
#include <ros/ros.h>
#include <string>

using namespace std;

RobotManager::RobotManager(ros::NodeHandle *nh_, string topic_name,
                           string robot_name, string robot_model)
    : odometry_topic{topic_name}, robot_name{robot_name}, robot_model{
                                                              robot_model} {
  odom_subscriber =
      nh_->subscribe(odometry_topic, 1000, &RobotManager::odom_callback, this);
}

void RobotManager::print_specifications() {
  ROS_INFO("Robot name: %s", robot_name.c_str());
  ROS_INFO("Robot model: %s", robot_model.c_str());
  ROS_INFO("Robot battery capacity (kWh): %f", battery_capacity_kwh);
  ROS_INFO("Robot total operation hours: %d", total_operation_hours);
}

void RobotManager::odom_callback(const nav_msgs::OdometryConstPtr &msg) {
  ROS_INFO("%s position (x, y): %f, %f", robot_name.c_str(),
           msg->pose.pose.position.x, msg->pose.pose.position.y);
}
