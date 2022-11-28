#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include "colormod.h"

Color::Modifier red(Color::FG_RED);
Color::Modifier def(Color::FG_DEFAULT);

void publish(int argc, char **argv)
{
    ros::init(argc, argv, "publisher");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::String>("chat", 1000 /*ms*/);
    ros::Rate loop_rate(10 /*Hz*/);
    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss,ss2;
        ss <<"hello world " << count;
        ss2 << red << "hello world " << count;
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO(ss2.str().c_str());
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
}

int main()
{

    publish(0, NULL);
    return 0;
}