#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"
#include "husky_follow/husky_follow.hpp"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "huskyFollow");
    ros::NodeHandle nodeHandle;
    HuskyFollow huskyFollow(nodeHandle);
    return 0;
}

