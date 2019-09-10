#include "husky_follow/husky_follow.hpp"
#include <geometry_msgs/Twist.h>

HuskyFollow::HuskyFollow(ros::NodeHandle &nodeHandle):nodeHandle(nodeHandle)
{
    laserSub = nodeHandle.subscribe("/scan", 1, &HuskyFollow::LaserCallBack, this);
    cmdPub = nodeHandle.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    ros::spin();
}
void HuskyFollow::LaserCallBack(const sensor_msgs::LaserScan::ConstPtr &msg)
{
    unsigned long len = msg->ranges.size();
    float minrange=msg->range_max;
    unsigned int minrangeID=0;
    for(int i=0; i<len; i++)
    {
        if(std::isnormal(msg->ranges[i]) && minrange>(msg->ranges[i]))
        {
            minrange=(msg->ranges[i]);
            minrangeID = i;
        }
    }
    float az=minrangeID*(msg->angle_increment)+(msg->angle_min);
    ROS_INFO_STREAM(minrange);
    ROS_INFO_STREAM(az);
    geometry_msgs::Twist twist;
    geometry_msgs::Vector3 linear;
    geometry_msgs::Vector3 angular;
    if(minrange>(msg->range_min)&&minrange<(msg->range_max)&&minrange>0.2)
    {
        linear.x=msg->range_min;
        linear.y=0;
        linear.z=0;
        angular.x=0;
        angular.y=0;
        angular.z=-az;
        twist.linear=linear;
        twist.angular=angular;
        cmdPub.publish(twist);
        ROS_INFO_STREAM(twist);
    }
}



