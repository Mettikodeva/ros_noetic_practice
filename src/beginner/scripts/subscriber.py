#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from termcolor import colored


def callback(data):
    msg = rospy.get_caller_id() + " I heard %s" % data.data
    rospy.loginfo(colored(msg, "green"))


def subscriber():
    rospy.init_node("subscriber", anonymous=True)
    rospy.Subscriber("chat", String, callback)  # chat is the topic here
    rospy.spin()


if __name__ == "__main__":
    subscriber()
