#include "ros/forwards.h"
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <string>

using namespace std;

class RobotManager {
  string robot_name;
  string robot_model;
  float battery_capacity_kwh = 4.5;
  int total_operation_hours = 4;

  // ROS
  ros::Subscriber odom_subscriber;
  string odometry_topic = "/odom";

public:
  RobotManager(ros::NodeHandle *nh_, string topic_name, string robot_name,
               string robot_model);
  void print_specifications();
  void odom_callback(const nav_msgs::OdometryConstPtr &msg);
};