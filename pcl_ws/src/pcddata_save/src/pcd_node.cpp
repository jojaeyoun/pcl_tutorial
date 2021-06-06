#include <ros/ros.h>

#include "pcd_save/pcd_save.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pcd_save");
    Pcd_saver p;
    ros::spin();
    return 0;
}