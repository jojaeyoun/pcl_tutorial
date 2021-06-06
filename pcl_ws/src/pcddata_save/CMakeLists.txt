cmake_minimum_required(VERSION 3.0.2)
project(pcddata_save)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
  pcl_ros
  pcl_conversions
)

find_package(PCL 1.7 REQUIRED) 
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS}) 
add_definitions(${PCL_DEFINITIONS}) 

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pcddata_save
#  CATKIN_DEPENDS roscpp rospy sensor_msgs std_msgs
#  DEPENDS system_lib
)


include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)


add_executable(pcd_save 
              src/pcd_node.cpp
              src/pcd.cpp
              include/pcd_save/pcd_save.h
              )
target_link_libraries(pcd_save 
                     ${PCL_LIBRARIES}
                     ${catkin_LIBRARIES}
                     )
