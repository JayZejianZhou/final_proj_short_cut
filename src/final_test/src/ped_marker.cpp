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
//This function is used to generate path markers in rviz

  //path 0-------0 based
  visualization_msgs::Marker path;
  path.header.frame_id="/map";
  path.header.stamp=ros::Time::now();
  path.ns="path0";
  path.id=0;// 0---based
  path.action=visualization_msgs::Marker::ADD;
  path.type=visualization_msgs::Marker::LINE_STRIP;
  path.scale.x=0.1;
  path.color.r=0.9f;
  path.color.g=1.0f;
  path.color.b=0.9f;
  path.color.a=1.0f;
  paths.push_back(path);

  //path 1-------0 based
  visualization_msgs::Marker path1;
  path1.header.frame_id="/map";
  path1.header.stamp=ros::Time::now();
  path1.ns="path1";
  path1.id=1;// 0---based
  path1.action=visualization_msgs::Marker::ADD;
  path1.type=visualization_msgs::Marker::LINE_STRIP;
  path1.scale.x=0.1;
  path1.color.r=0.0f;
  path1.color.g=1.0f;
  path1.color.b=0.0f;
  path1.color.a=1.0f;
  paths.push_back(path1);

  //path 1-------1 based
  visualization_msgs::Marker path2;
  path2.header.frame_id="/map";
  path2.header.stamp=ros::Time::now();
  path2.ns="path2";
  path2.id=2;// 0---based
  path2.action=visualization_msgs::Marker::ADD;
  path2.type=visualization_msgs::Marker::LINE_STRIP;
  path2.scale.x=0.1;
  path2.color.r=0.8f;
  path2.color.g=1.0f;
  path2.color.b=0.8f;
  path2.color.a=1.0f;
  paths.push_back(path2);

  //path 1-------1 based
  visualization_msgs::Marker path3;
  path3.header.frame_id="/map";
  path3.header.stamp=ros::Time::now();
  path3.ns="path3";
  path3.id=3;// 0---based
  path3.action=visualization_msgs::Marker::ADD;
  path3.type=visualization_msgs::Marker::LINE_STRIP;
  path3.scale.x=0.1;
  path3.color.r=0.7f;
  path3.color.g=1.0f;
  path3.color.b=0.7f;
  path3.color.a=1.0f;
  paths.push_back(path3);

  //path 1-------1 based
  visualization_msgs::Marker path4;
  path4.header.frame_id="/map";
  path4.header.stamp=ros::Time::now();
  path4.ns="path4";
  path4.id=4;// 0---based
  path4.action=visualization_msgs::Marker::ADD;
  path4.type=visualization_msgs::Marker::LINE_STRIP;
  path4.scale.x=0.1;
  path4.color.r=0.6f;
  path4.color.g=1.0f;
  path4.color.b=0.6f;
  path4.color.a=1.0f;
  paths.push_back(path4);

  //path 5-------0 based
  visualization_msgs::Marker path5;
  path5.header.frame_id="/map";
  path5.header.stamp=ros::Time::now();
  path5.ns="path5";
  path5.id=5;// 0---based
  path5.action=visualization_msgs::Marker::ADD;
  path5.type=visualization_msgs::Marker::LINE_STRIP;
  path5.scale.x=0.1;
  path5.color.r=0.5f;
  path5.color.g=1.0f;
  path5.color.b=0.5f;
  path5.color.a=1.0f;
  paths.push_back(path5);

  //path 6-------0 based
  visualization_msgs::Marker path6;
  path6.header.frame_id="/map";
  path6.header.stamp=ros::Time::now();
  path6.ns="path6";
  path6.id=6;// 0---based
  path6.action=visualization_msgs::Marker::ADD;
  path6.type=visualization_msgs::Marker::LINE_STRIP;
  path6.scale.x=0.1;
  path6.color.r=0.4f;
  path6.color.g=1.0f;
  path6.color.b=0.4f;
  path6.color.a=1.0f;
  paths.push_back(path6);

  //path 7-------0 based
  visualization_msgs::Marker path7;
  path7.header.frame_id="/map";
  path7.header.stamp=ros::Time::now();
  path7.ns="path7";
  path7.id=7;// 0---based
  path7.action=visualization_msgs::Marker::ADD;
  path7.type=visualization_msgs::Marker::LINE_STRIP;
  path7.scale.x=0.1;
  path7.color.r=0.3f;
  path7.color.g=1.0f;
  path7.color.b=0.3f;
  path7.color.a=1.0f;
  paths.push_back(path7);

  //path 8-------0 based
  visualization_msgs::Marker path8;
  path8.header.frame_id="/map";
  path8.header.stamp=ros::Time::now();
  path8.ns="path8";
  path8.id=8;// 0---based
  path8.action=visualization_msgs::Marker::ADD;
  path8.type=visualization_msgs::Marker::LINE_STRIP;
  path8.scale.x=0.1;
  path8.color.r=0.2f;
  path8.color.g=1.0f;
  path8.color.b=0.2f;
  path8.color.a=1.0f;
  paths.push_back(path8);

  //path 9-------0 based
  visualization_msgs::Marker path9;
  path9.header.frame_id="/map";
  path9.header.stamp=ros::Time::now();
  path9.ns="path9";
  path9.id=9;// 0---based
  path9.action=visualization_msgs::Marker::ADD;
  path9.type=visualization_msgs::Marker::LINE_STRIP;
  path9.scale.x=0.1;
  path9.color.r=0.1f;
  path9.color.g=1.0f;
  path9.color.b=0.1f;
  path9.color.a=1.0f;
  paths.push_back(path9);


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
