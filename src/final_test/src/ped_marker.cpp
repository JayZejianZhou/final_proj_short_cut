/*
 * Maintained by JayZejianZhou
 * All rights reserved
 */

#include <ped_marker.h>
#include <visualization_msgs/Marker.h>
#include <vector>
#include <pedsim/ped_agent.h>
#include <pedsim/ped_scene.h>

void marker_initiate(std::vector<visualization_msgs::Marker> &paths){
//generate path markers in rviz
  for(int i=0;i<10;i++){
    visualization_msgs::Marker path;
    path.header.frame_id="/map";
    path.header.stamp=ros::Time::now();
    path.ns="path";
    path.id=i;// 0---based
    path.action=visualization_msgs::Marker::ADD;
    path.type=visualization_msgs::Marker::LINE_STRIP;
    path.scale.x=0.1;
    path.color.r=i/10;
    path.color.g=1;
    path.color.b=i/10;
    path.color.a=1.0f;
    paths.push_back(path);
  }
////generate scene boundries markers
//  for(int i=0;i<4;i++){
//    visualization_msgs::Marker scene;
//    scene.header.frame_id="/map";
//    scene.header.stamp=ros::Time::now();
//    scene.ns="path";
//    scene.id=i;// 0---based
//    scene.action=visualization_msgs::Marker::ADD;
//    scene.type=visualization_msgs::Marker::LINE_STRIP;
//    scene.scale.x=0.5;
//    scene.color.r=1;
//    scene.color.g=0;
//    scene.color.b=0;
//    scene.color.a=1.0f;
//    scenes.push_back(scene);
//  }
}

//this function draw paths for every agent
void draw_path(std::vector<visualization_msgs::Marker> &paths, Ped::Tscene *scene){
  for(Ped::Tagent* agent : scene->getAllAgents()){
    geometry_msgs::Point p;
    p.x=agent->getPosition().x;
    p.y=agent->getPosition().y;
    p.z=0;
//    std::cout<<agent->getid()<<' '<<agent->getPosition().x<<' '<<agent->getPosition().y<<'\n';
//    std::cout<<agent->getid()<<'\n';
//    if(agent->getid()==0)
      paths[agent->getid()].points.push_back(p);
  }
}
