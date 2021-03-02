#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include <cmath>

using namespace std;

void chatterCallback1(const std_msgs::UInt16::ConstPtr& msg)
{
    ROS_INFO("%d", msg->data);

    ros::NodeHandle n2;

    int res = pow(msg->data, 2);
    ros::Publisher pub2 = n2.advertise<std_msgs::UInt16>("Subscriber2", 1000);
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        std_msgs::UInt16 msg;

        msg.data = res;
        pub2.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node2");
    ros::NodeHandle n;

    ros::Subscriber sub1 = n.subscribe("Subscriber1", 1000, chatterCallback1);
    ros::spin();
    
    return 0;
}