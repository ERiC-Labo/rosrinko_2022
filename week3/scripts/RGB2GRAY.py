#!/usr/bin/env python3
from torch import threshold
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

# コールバック関数
def process_image(msg):
    try:
        bridge = CvBridge()
        # subscribeしたImage型のmsgをopencvで扱える形式に変換
        original = bridge.imgmsg_to_cv2(msg, "bgr8")
        # グレースケール画像の作成
        img = cv2.cvtColor(original, cv2.COLOR_BGR2GRAY)
        # 輪郭抽出
        canny = cv2.Canny(original,127,127)

        # opencv型からImage型のmsgに変換
        imgMsg = bridge.cv2_to_imgmsg(img, "mono8")
        cannyMsg = bridge.cv2_to_imgmsg(canny,"mono8")
        
        # publish
        pub = rospy.Publisher('image_gray', Image, queue_size=10)
        pub.publish(imgMsg)
        canny_pub = rospy.Publisher('canny', Image, queue_size=10)
        canny_pub.publish(cannyMsg)
    except Exception as err:
        print(err)

def start_node():
    # nodeの初期化
    rospy.init_node('img_proc')
    rospy.loginfo('img_proc node started')
    # subscribeする
    rospy.Subscriber("/usb_cam/image_raw", Image, process_image)
    rospy.spin()

if __name__ == '__main__':
    try:
        start_node()
    except rospy.ROSInterruptException:
        pass