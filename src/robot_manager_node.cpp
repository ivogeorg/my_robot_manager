#include "my_robot_manager/robot_manager.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "my_robot_manager_node");
    
    RobotManager robot;
    robot.robot_name = "ToyBot";
    robot.robot_model = "TurtleBot3";

    robot.print_specifications();

    return 0;
}