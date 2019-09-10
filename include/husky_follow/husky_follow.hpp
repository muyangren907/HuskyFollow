#pragma once
#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"
class HuskyFollow
{
public:
    HuskyFollow(ros::NodeHandle &nodeHandle);

private:
    void LaserCallBack(const sensor_msgs::LaserScan::ConstPtr &msg);
    ros::NodeHandle &nodeHandle;
    ros::Subscriber laserSub;
    ros::Publisher cmdPub;
};


