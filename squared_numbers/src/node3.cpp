#include "ros/ros.h"
#include "std_msgs/UInt16.h"

void chatterCallback2(const std_msgs::UInt16::ConstPtr& msg)
{
    ROS_INFO("%d", msg->data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node3");
    ros::NodeHandle n;

    ros::Subscriber sub2 = n.subscribe("Subscriber2", 1000, chatterCallback2);
    ros::spin();

    return 0;
}