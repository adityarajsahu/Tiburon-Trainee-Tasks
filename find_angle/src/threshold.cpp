# include <ros/ros.h>
#include <image_transport/image_transport.h>
# include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
# include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
# include <sstream>

using namespace cv;

const char* window_name = "Threshold Demo";

int main(int argc, char **argv)
{
    ros::init(argc, argv, "threshold");
    ros::NodeHandle n;
    image_transport::ImageTransport it(n);
    image_transport::Publisher pub = it.advertise("camera/image", 1);

    cv::VideoCapture cap("/home/Downloads/InputVideo.mp4");

    if(!cap.isOpened())
    {
        return -1;
    } 

    Mat frame;
    sensor_msgs::ImagePtr msg;

    ros::Rate loop_rate(30);
    while(nh.ok())
    {
        cap >> frame;
        if(!frame.empty())
        {
            Mat gray;
            cvtColor(frame, gray, COLOR_BGR2GRAY);

            threshold(gray, threshold, 100, 255, 0);
            imshow(window_name, threshold);

            msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", threshold).toImageMSg();
            pub.publish(msg);
            cv::waitKey(1);
        }
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}