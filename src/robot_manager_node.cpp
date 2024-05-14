#include "my_robot_manager/robot_manager.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "my_robot_manager_node");
    
    ros::NodeHandle nh;
    RobotManager robot1(&nh, "/robot1/odom", "ToyBot", "TurtleBot3");
    RobotManager robot2(&nh, "/robot2/odom", "BoyTot", "TurtleBot3");

    robot1.print_specifications();
    robot2.print_specifications();
    ros::spin();

    return 0;
}