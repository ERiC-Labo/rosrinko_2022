#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int64.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "basic_simple_talker");
  ros::NodeHandle nh;
  ros::Publisher chatter_pub = nh.advertise<std_msgs::Int64>("chatter", 10);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    std_msgs::Int64 num;
    num.data = 12345;
    ROS_INFO("publish: %d", num.data);
    chatter_pub.publish(num);

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}