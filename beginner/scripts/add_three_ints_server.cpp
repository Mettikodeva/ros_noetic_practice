#include <ros/ros.h>
#include <beginner/AddThreeInts.h>

bool handle_add_three_ints(beginner::AddThreeInts::Request &req,
                           beginner::AddThreeInts::Response &res)
{
    ROS_INFO("request : x= %ld, y= %ld, z= %ld", (long int)req.a, (long int)req.b, (long int)req.c);
    res.ans = req.a + req.b + req.c;
    ROS_INFO("sending back response: %ld", res.ans);
    return true;
}

int main(int arc, char**argv){
    ros::init(arc, argv, "add_three_ints_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("add_three_ints", handle_add_three_ints);
    ROS_INFO("Ready to add three ints.");
    ros::spin();
    return 0;
}