#ifndef PED_MARKER_H
#define PED_MARKER_H

#include <visualization_msgs/Marker.h>
#include <vector>
#include <pedsim/ped_scene.h>


void marker_initiate(std::vector<visualization_msgs::Marker> &paths);

void draw_path(std::vector<visualization_msgs::Marker> &paths, Ped::Tscene * scene);



#endif // PED_MARKER_H
