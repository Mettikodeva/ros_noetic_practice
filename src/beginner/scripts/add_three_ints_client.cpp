#include <ros/ros.h>
#include <beginner/AddThreeInts.h>

void add_three_ints_clients(int x, int y, int z, int &answer){

}

int main(int argc, char**argv){

    ros::init(argc,argv,"add_three_ints_client");

    if(argc !=4){
        ROS_INFO("usage : add_three_ints_client x y z");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<beginner::AddThreeInts>("add_three_ints");
    beginner::AddThreeInts srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    srv.request.c = atoll(argv[3]);
    if(client.call(srv)){
        ROS_INFO("Sum: %ld", (long int)srv.response.ans);
    }
    else{
        ROS_ERROR("failed to call service add_three_ints");
    }
}