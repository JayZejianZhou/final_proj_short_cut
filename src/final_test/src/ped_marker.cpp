/*
 * Maintained by JayZejianZhou
 * All rights reserved
 */

#include <ped_marker.h>
#include <visualization_msgs/Marker.h>
#include <vector>
#include <pedsim/ped_agent.h>
#include <pedsim/ped_scene.h>
#include <pedsim/ped_obstacle.h>
#include <ros/ros.h>

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
    path.color.g=0.5;
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

// read in parameters from XML file
void read_in_param(ros::NodeHandle & nh, int *scene_data, int *waypoint){
  nh.param<int>("scene_left",scene_data[0],-200);
  nh.param<int>("scene_top",scene_data[1],-200);
  nh.param<int>("scene_width",scene_data[2],-200);
  nh.param<int>("scene_height",scene_data[3],-200);

  nh.param<int>("w1_x",waypoint[0],-200);
  nh.param<int>("w1_y",waypoint[1],-200);
  nh.param<int>("w1_r",waypoint[2],-200);
  nh.param<int>("w2_x",waypoint[3],-200);
  nh.param<int>("w2_y",waypoint[4],-200);
  nh.param<int>("w2_r",waypoint[5],-200);
}

//set obstacle
void set_obstacle(ros::Publisher & scene_pub,Ped::Tscene * pedscene, int top, int down, int left, int right){
  //set the visualization
  visualization_msgs::Marker obs;
  obs.header.frame_id="/map";
  obs.header.stamp=ros::Time::now();
  obs.ns="obstacle";
  obs.id=0;
  obs.action=visualization_msgs::Marker::ADD;
  obs.type=visualization_msgs::Marker::CUBE;
  obs.pose.position.x=(left+right)/2;
  obs.pose.position.y=(top+down)/2;
  obs.pose.position.z=0;
  obs.pose.orientation.x=0;
  obs.pose.orientation.y=0;
  obs.pose.orientation.z=0;
  obs.pose.orientation.w=0;
  obs.scale.x=(right-left)/2;
  obs.scale.y=(down-top)/2;
  obs.scale.z=4.0;
  obs.color.r=1.0f;
  obs.color.g=0.0f;
  obs.color.b=0.0f;
  obs.color.a=1.0;
  obs.lifetime=ros::Duration();
  scene_pub.publish(obs);

  //set the obstacle in pedsim
  Ped::Tobstacle *o = new Ped::Tobstacle(left,top,right,down);
  pedscene->addObstacle(o);
}

