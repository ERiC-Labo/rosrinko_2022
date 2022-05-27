#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int64.h>

void chatterCallback(const std_msgs::Int64& num)
{
  ROS_INFO("subscribe: %d", num.data);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "basic_simple_listener");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("chatter", 10, chatterCallback);

  ros::spin();
  return 0;
}