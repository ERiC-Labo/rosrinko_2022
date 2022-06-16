#include <ros/ros.h>
#include <week2/service_talker.h>

using namespace std;

bool Greetings(week2::service_talker::Request &req, week2::service_talker::Response &res)
{
    res.greeting = req.a1 + req.a2;
    ROS_INFO_STREAM("request: a1 = " + req.a1 + ", a2 = " + req.a2);
    ROS_INFO_STREAM("sending back response: " + res.greeting);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "greeting_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("greeting", Greetings);
    ROS_INFO("Wait");
    ros::spin();

    return 0;
}

// string Greetings(week2::service_talker::Request &req, week2::service_talker::Response &res)
// {
//     res.greeting = req.a1 + req.a2;
//     ROS_INFO_STREAM("request: a1 = " + req.a1 + ", a2 = " + req.a2);
//     ROS_INFO_STREAM("sending back response: " + res.greeting);
//     return res.greeting;
// }