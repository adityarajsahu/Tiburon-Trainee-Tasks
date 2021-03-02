#include "ros/ros.h"
#include "complex_calculations/ComplexNum.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node1");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<complex_calculations::ComplexNum>("Subscriber", 1000);
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        int realpart1 = rand(), imgpart1 = rand(), realpart2 = rand(), imgpart2 = rand();

        char letters[] = "asm";
        char x = letters[rand() % 3];

        complex_calculations::ComplexNum msg;
        msg.real1 = realpart1;
        msg.imaginary1 = imgpart2;
        msg.real2 = realpart1;
        msg.imaginary2 = imgpart2;
        msg.oper = x;

        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}