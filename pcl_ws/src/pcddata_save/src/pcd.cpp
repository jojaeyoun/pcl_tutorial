#include "pcd_save/pcd_save.h"

#include <ros/ros.h>

Pcd_saver::Pcd_saver()
    :nh("")
    ,pnh("~")
{   
    ROS_INFO("Creat Pcd saver!");

    pnh.param<std::string>("savefile_path",savefile_path,"/home/jaeyun/pcl_ws/src/data/");
    pnh.param<std::string>("lidar_topic", lidar_topic, "velodyne_left");
    pnh.param<int>("pcdfile_cnt", pcdfile_cnt, 5);
    
    sub_velodyne = nh.subscribe(lidar_topic, 1, &Pcd_saver::velodyne_cb,this);

    pcd_data.reset(new pcl::PointCloud<pcl::PointXYZ>);
}


void Pcd_saver::make_pcdfile(std::string savefile_path, int pcdfile_cnt)
{
    if(!pcd_data->empty() && check_cnt == false)
    {
        for(int i=1; i<=pcdfile_cnt; i++)
        {
            ROS_INFO_STREAM("pcd file saved : " << i << std::endl);
            pcl::io::savePCDFileASCII(std::to_string(i)+".pcd", *pcd_data);
        }

        check_cnt = true;
        ros::shutdown();
    }
}


void Pcd_saver::velodyne_cb(const sensor_msgs::PointCloud2::ConstPtr &input)
{

    if(input->data.size() > 0) 
    {
        ROS_INFO("subscribe lidar Topic!");

        pcl::fromROSMsg(*input, *pcd_data);
        make_pcdfile(this->savefile_path, this->pcdfile_cnt);
    }
    else    
    {
        ROS_INFO("Waiting... pcd data");
    }
}
