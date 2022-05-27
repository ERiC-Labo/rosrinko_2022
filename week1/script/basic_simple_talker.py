#!/usr/bin/env python3
# license removed for brevity
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int64

def talker():
     pub = rospy.Publisher('chatter', Int64, queue_size=10)
     rospy.init_node('talker', anonymous=True)
     r = rospy.Rate(10) # 10hz
     while not rospy.is_shutdown():
         num = 54321
         rospy.loginfo("publish:%d",num)
         pub.publish(num)
         r.sleep()
 
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass