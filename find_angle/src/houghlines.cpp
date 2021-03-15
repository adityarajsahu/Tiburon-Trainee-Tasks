#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <bits/stdc++.h>

using namespace cv;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    Mat frame, colored, colored_clone, hough;

    frame = cv_bridge::toCvShare(msg, "bgr8")->image;
    cvtColor(frame, colored, COLOR_GRAY2BGR);
    hough_clone = colored.clone();

    vector<Vec2f> lines;
    HoughLines(colored, lines, 1, CV_PI/180, 150, 0, 0);

}

int main(int argc, char **argv)
{
    ros::init_node("houghlines");
    ros::NodeHandle n;

    cv::namedWindow("view2");
    cv::startWindowThread();
    image_transport::ImageTransport it(n);
    image_transport::Subscriber sub = it.subscribe("camera/image2", 1, imageCallback);
    ros::spin();
    cv::destroyWindow("view2");
    return 0;
}