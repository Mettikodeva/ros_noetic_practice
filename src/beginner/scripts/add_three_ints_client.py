
import sys
import rospy
from beginner.srv import AddThreeInts, AddThreeIntsRequest

def add_three_ints_client(x, y, z):
    rospy.wait_for_service('add_three_ints')
    try:
        add_three_ints = rospy.ServiceProxy('add_three_ints', AddThreeInts)
        resp1 = add_three_ints(x, y, z)
        return resp1.ans
    except (rospy.ServiceException):
        print ("Service call failed:")

def usage():
    return ("%s [x y z]" %sys.argv[0])

if __name__ == "__main__":
    print(sys.argv)
    if(len(sys.argv) == 4):
        x = int(sys.argv[1])
        y = int(sys.argv[2])
        z = int(sys.argv[3])
    else:
        print (usage())
        sys.exit(1)
    print ("Requesting %s + %s + %s" %(x, y, z))
    print ("%s + %s + %s = %s" %(x, y, z, add_three_ints_client(x, y, z)))