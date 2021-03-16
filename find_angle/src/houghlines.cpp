#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    Mat frame, colored, colored_clone, hough;

    frame = cv_bridge::toCvShare(msg, "bgr8")->image;
    cvtColor(frame, colored, COLOR_GRAY2BGR);
    colored_clone = colored.clone();

    vector<Vec2f> lines;
    HoughLines(colored, lines, 1, CV_PI/180, 150, 0, 0);

    float theta1 = lines[0][1], theta2 = lines[1][1];
    float m1 = tan(theta1), m2 = tan(theta2);

    float tan_of_angle = (m2-m1)/(1+ (m1*m2));
    float angle = atan(tan_of_angle);

    string disp = "Angle formed : " + to_string(angle);
    putText(colored, disp, Point(50,50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 200, 200), 4);

    imshow("Angle", colored);
    waitKey(0);
    destroyWindow("Angle");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "houghlines");
    ros::NodeHandle n;

    cv::namedWindow("view2");
    cv::startWindowThread();
    image_transport::ImageTransport it(n);
    image_transport::Subscriber sub = it.subscribe("camera/image2", 1, imageCallback);
    ros::spin();
    cv::destroyWindow("view2");
    return 0;
}