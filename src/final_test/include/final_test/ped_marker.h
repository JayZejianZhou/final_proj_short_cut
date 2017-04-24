#ifndef PED_MARKER_H
#define PED_MARKER_H

#include <visualization_msgs/Marker.h>
#include <vector>
#include <pedsim/ped_scene.h>
#include <ros/ros.h>


void marker_initiate(std::vector<visualization_msgs::Marker> &paths,int num);

void draw_path(std::vector<visualization_msgs::Marker> &paths, Ped::Tscene * scene);
void read_in_param(ros::NodeHandle & nh, int *scene_data, int * waypoint, double speed);
void set_obstacle(ros::Publisher & scene_pub, Ped::Tscene *pedscene, int top, int down, int left, int right);
void set_scene_boundry(ros::Publisher & scene_pub,Ped::Tscene * pedscene, int top, int down, int left, int right);

#endif // PED_MARKER_H
