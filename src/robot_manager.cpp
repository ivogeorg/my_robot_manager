#include "my_robot_manager/robot_manager.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <string>

using namespace std;

int RobotManager::robot_count = 0;

RobotManager::RobotManager(ros::NodeHandle *nh_, string topic_name,
                           string robot_name, string robot_model)
    : odometry_topic{topic_name}, robot_name{robot_name},
      robot_model{robot_model}, odom_subscriber{nh_->subscribe(
                                    odometry_topic, 1000,
                                    &RobotManager::odom_callback, this)},
      _pos_srv{nh_->advertiseService(robot_name +
                                         "/log_current_position",
                                     &RobotManager::service_callback, this)} {
  robot_count++;
  ROS_INFO("Robot %d created.", robot_count);
}

void RobotManager::print_specifications() const {
  ROS_INFO("Robot name: %s", robot_name.c_str());
  ROS_INFO("Robot model: %s", robot_model.c_str());
  ROS_INFO("Robot battery capacity (kWh): %f", battery_capacity_kwh);
  ROS_INFO("Robot total operation hours: %d", total_operation_hours);
}

void RobotManager::odom_callback(const nav_msgs::OdometryConstPtr &msg) {
  this->current_x_position = msg->pose.pose.position.x;
  this->current_y_position = msg->pose.pose.position.y;
}

bool RobotManager::service_callback(
      std_srvs::Trigger::Request &req,
      std_srvs::Trigger::Response &res) {
  ROS_INFO("%s position (x, y): %f, %f", robot_name.c_str(),
           current_x_position, current_y_position);
  res.success = true;
  res.message = "Position logged";
  return true;
}
