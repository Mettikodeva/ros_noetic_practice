#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from termcolor import colored


def publisher():
    pub = rospy.Publisher("chat", String, queue_size=10)  # chat is the topic here
    rospy.init_node("publisher", anonymous=True)
    rate = rospy.Rate(1)  # 1hz
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.loginfo(colored(hello_str, "blue"))
        pub.publish(hello_str)
        rate.sleep()


if __name__ == "__main__":
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
