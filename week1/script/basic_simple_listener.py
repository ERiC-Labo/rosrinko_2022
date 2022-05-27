#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int64

def callback(data):
    rospy.loginfo("subscribe:%d",data.data)

def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber("chatter", Int64, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()