#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include "colormod.h"

Color::Modifier blue(Color::FG_BLUE);
Color::Modifier def(Color::FG_DEFAULT);
void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
    std::stringstream ss;
    ss << blue << "I heard: [" << msg->data.c_str()<<"]"<<def;
    ROS_INFO(ss.str().c_str());
}

void subscriber(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chat", 1000 /*ms*/, chatterCallback);
    ros::spin();
}

int main()
{
    subscriber(0, NULL);
    return 0;
}