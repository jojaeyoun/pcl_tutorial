#include <ros/ros.h>

#include <sensor_msgs/PointCloud2.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>

#include <iostream>
#include <string>

class Pcd_saver
{
public :
    Pcd_saver();

private :

    void velodyne_cb(const sensor_msgs::PointCloud2::ConstPtr &input);
    void make_pcdfile(std::string savefile_path, int pcdfile_cnt);
    void callback(const ros::TimerEvent& event);

    // ros
    ros::NodeHandle nh;
    ros::NodeHandle pnh;

    ros::Subscriber sub_velodyne;
    
    //param 
    std::string savefile_path;
    std::string lidar_topic;
    int pcdfile_cnt;

    // variable
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcd_data;
    bool check_cnt = false;
    
};