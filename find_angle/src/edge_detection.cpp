# include <ros/ros.h>
#include <image_transport/image_transport.h>
# include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
# include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
# include <sstream>

using namespace cv;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    Mat frame;

    frame = cv_bridge::toCvShare(msg, "bgr8")->image;
    Canny(frame, canny_edge, 100, 100, 3);
    msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", canny_edge).toImageMSg();
    pub.publish();
} 


int main(int argc, char **argv)
{
    ros::init(argc, argv, "edge_detection");
    ros::NodeHandle n;

    cv::namedWindow("view1");
    cv::startWindowThread();
    image_transport::ImageTransport it(n);
    image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
    pub = it.advertise("camera/image2", 1);
    ros::spin();
    cv::destroyWindow("view1");
    return 0;
}