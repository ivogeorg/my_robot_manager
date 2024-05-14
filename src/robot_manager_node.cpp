#include "my_robot_manager/robot_manager.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "my_robot_manager_node");
    
    ros::NodeHandle nh;
    RobotManager robot(&nh, "/robot1/odom", "ToyBot", "TurtleBot3");

    robot.print_specifications();
    ros::spin();

    return 0;
}