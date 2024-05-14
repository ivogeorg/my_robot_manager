#include "ros/forwards.h"
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>
#include <std_srvs/Trigger.h>

using namespace std;

class RobotManager {
  string robot_name;
  string robot_model;
  float battery_capacity_kwh = 4.5;
  int total_operation_hours = 4;

  // Odom
  float current_x_position;
  float current_y_position;

  // ROS
  string odometry_topic = "/odom";
  ros::Subscriber odom_subscriber;
  ros::ServiceServer _pos_srv;

public:
  static int robot_count;

  RobotManager(ros::NodeHandle *nh_, string topic_name, string robot_name,
               string robot_model);
  void print_specifications() const;
  void odom_callback(const nav_msgs::OdometryConstPtr &msg);
  bool service_callback(
      std_srvs::Trigger::Request &req,
      std_srvs::Trigger::Response &res);
};