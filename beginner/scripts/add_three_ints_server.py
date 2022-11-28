#!/usr/bin/env python

import rospy
from beginner.srv import AddThreeInts, AddThreeIntsResponse

def handle_add_three_ints(req):
    print ("Returning [%s + %s + %s = %s]"%(req.a, req.b, req.c, (req.a + req.b + req.c)))
    return AddThreeIntsResponse(req.a + req.b + req.c)

def add_three_ints_server():

    rospy.init_node('add_three_ints_server')
    s = rospy.Service('add_three_ints', AddThreeInts, handle_add_three_ints)
    print ("Ready to add three ints.")
    rospy.spin()

if __name__ == "__main__":
    add_three_ints_server()
