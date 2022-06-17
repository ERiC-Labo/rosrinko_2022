#include <ros/ros.h>
#include <week2/service_talker.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "service_listener");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<week2::service_talker>("greeting");

    week2::service_talker srv;
    cout << "Enter a greeting" << endl;
    cin >> srv.request.a1;
    cin >> srv.request.a2;

    if (client.call(srv))
    {
        ROS_INFO_STREAM("Greetings: " + srv.response.greeting);
    }
    else
    {
        ROS_ERROR("Failed to call service greeting");
        return 1;
    }

    return 0;
}
