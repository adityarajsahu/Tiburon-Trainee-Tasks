#include "ros/ros.h"
#include "std_msgs/UInt16.h"

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node1");
    ros::NodeHandle n;

    ros::Publisher pub1 = n.advertise<std_msgs::UInt16>("Subscriber1", 1000);
    ros::Rate loop_rate(10);

    int num = 1;
    while(ros::ok())
    {
        std_msgs::UInt16 msg;
        msg.data = num;

        pub1.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        num++;
    }
    return 0;
}