#include "ros/ros.h"
#include "complex_calculations/ComplexNum.h"

void chatterCallback(const complex_calculations::ComplexNum::ConstPtr& msg)
{
    if(msg->oper == 'a')
    {
        int real_sum = msg->real1 + msg->real2;
        int img_sum = msg->imaginary1 + msg->imaginary2;

        ROS_INFO("%d + %d i", real_sum, img_sum);
    }
    else if(msg->oper == 's')
    {
        int real_sum = msg->real1 - msg->real2;
        int img_sum = msg->imaginary1 - msg->imaginary2;

        ROS_INFO("%d + %d i", real_sum, img_sum);
    }
    else if(msg->oper == 'm')
    {
        int real_sum = (msg->real1 * msg->real2) - (msg->imaginary1 * msg->imaginary2);
        int img_sum = (msg->real1 * msg->imaginary2) + (msg->real2 * msg->imaginary1);

        ROS_INFO("%d + %d i", real_sum, img_sum);
    }
    else
    {
        ROS_INFO("Incorrect operator chosen.");
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node2");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("Subscriber", 1000, chatterCallback);
    ros::spin();

    return 0;
}