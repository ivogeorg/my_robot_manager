#include <ros/ros.h>
#include <string>

using namespace std;

class RobotManager {
public:
  string robot_name;
  string robot_model;
  float battery_capacity_kwh = 4.5;
  int total_operation_hours = 4;

  void print_specifications();

};