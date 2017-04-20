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
  //generate path markers in rviz-----------You can't use a for loop because the color of the 10 agents will be exacly the same
//  for(int i=0;i<10;i++){
//    visualization_msgs::Marker path;
//    path.header.frame_id="/map";
//    path.header.stamp=ros::Time::now();
//    path.ns="path";
//    path.id=i;// 0---based
//    path.action=visualization_msgs::Marker::ADD;
//    path.type=visualization_msgs::Marker::LINE_STRIP;
//    path.scale.x=0.1;
//    path.color.r=0.3;
//    path.color.g=0.3;
//    path.color.b=0.3;
//    path.color.a=1.0f;
//    paths.push_back(path);
//  }
  //generating path markers without a loop
      visualization_msgs::Marker path0;
      path0.header.frame_id="/map";
      path0.header.stamp=ros::Time::now();
      path0.ns="path";
      path0.id=0;// 0---based
      path0.action=visualization_msgs::Marker::ADD;
      path0.type=visualization_msgs::Marker::LINE_STRIP;
      path0.scale.x=0.1;
      path0.color.r=0.2;
      path0.color.g=0.3;
      path0.color.b=0.5;
      path0.color.a=1.0f;
      paths.push_back(path0);

      visualization_msgs::Marker path1;
      path1.header.frame_id="/map";
      path1.header.stamp=ros::Time::now();
      path1.ns="path";
      path1.id=1;// 0---based
      path1.action=visualization_msgs::Marker::ADD;
      path1.type=visualization_msgs::Marker::LINE_STRIP;
      path1.scale.x=0.1;
      path1.color.r=0.8;
      path1.color.g=0.1;
      path1.color.b=0.4;
      path1.color.a=1.0f;
      paths.push_back(path1);

      visualization_msgs::Marker path2;
      path2.header.frame_id="/map";
      path2.header.stamp=ros::Time::now();
      path2.ns="path2";
      path2.id=2;// 0---based
      path2.action=visualization_msgs::Marker::ADD;
      path2.type=visualization_msgs::Marker::LINE_STRIP;
      path2.scale.x=0.1;
      path2.color.r=0.6;
      path2.color.g=0.9;
      path2.color.b=0.45;
      path2.color.a=1.0f;
      paths.push_back(path2);

      visualization_msgs::Marker path3;
      path3.header.frame_id="/map";
      path3.header.stamp=ros::Time::now();
      path3.ns="path";
      path3.id=3;// 0---based
      path3.action=visualization_msgs::Marker::ADD;
      path3.type=visualization_msgs::Marker::LINE_STRIP;
      path3.scale.x=0.1;
      path3.color.r=0.7;
      path3.color.g=0.1;
      path3.color.b=0.4;
      path3.color.a=1.0f;
      paths.push_back(path3);

      visualization_msgs::Marker path4;
      path4.header.frame_id="/map";
      path4.header.stamp=ros::Time::now();
      path4.ns="path4";
      path4.id=4;// 0---based
      path4.action=visualization_msgs::Marker::ADD;
      path4.type=visualization_msgs::Marker::LINE_STRIP;
      path4.scale.x=0.1;
      path4.color.r=0.7;
      path4.color.g=0.43;
      path4.color.b=0.63;
      path4.color.a=1.0f;
      paths.push_back(path4);

      visualization_msgs::Marker path5;
      path5.header.frame_id="/map";
      path5.header.stamp=ros::Time::now();
      path5.ns="path";
      path5.id=5;// 0---based
      path5.action=visualization_msgs::Marker::ADD;
      path5.type=visualization_msgs::Marker::LINE_STRIP;
      path5.scale.x=0.1;
      path5.color.r=0.73;
      path5.color.g=0.83;
      path5.color.b=0.13;
      path5.color.a=1.0f;
      paths.push_back(path5);

      visualization_msgs::Marker path6;
      path6.header.frame_id="/map";
      path6.header.stamp=ros::Time::now();
      path6.ns="path";
      path6.id=6;// 0---based
      path6.action=visualization_msgs::Marker::ADD;
      path6.type=visualization_msgs::Marker::LINE_STRIP;
      path6.scale.x=0.1;
      path6.color.r=0.63;
      path6.color.g=0.33;
      path6.color.b=0.34;
      path6.color.a=1.0f;
      paths.push_back(path6);

      visualization_msgs::Marker path7;
      path7.header.frame_id="/map";
      path7.header.stamp=ros::Time::now();
      path7.ns="path7";
      path7.id=7;// 0---based
      path7.action=visualization_msgs::Marker::ADD;
      path7.type=visualization_msgs::Marker::LINE_STRIP;
      path7.scale.x=0.1;
      path7.color.r=0.563;
      path7.color.g=0.83;
      path7.color.b=0.13;
      path7.color.a=1.0f;
      paths.push_back(path7);

      visualization_msgs::Marker path8;
      path8.header.frame_id="/map";
      path8.header.stamp=ros::Time::now();
      path8.ns="path8";
      path8.id=8;// 0---based
      path8.action=visualization_msgs::Marker::ADD;
      path8.type=visualization_msgs::Marker::LINE_STRIP;
      path8.scale.x=0.1;
      path8.color.r=0.563;
      path8.color.g=0.63;
      path8.color.b=0.543;
      path8.color.a=1.0f;
      paths.push_back(path8);

      visualization_msgs::Marker path9;
      path9.header.frame_id="/map";
      path9.header.stamp=ros::Time::now();
      path9.ns="path9";
      path9.id=9;// 0---based
      path9.action=visualization_msgs::Marker::ADD;
      path9.type=visualization_msgs::Marker::LINE_STRIP;
      path9.scale.x=0.1;
      path9.color.r=0.33;
      path9.color.g=0.35;
      path9.color.b=0.63;
      path9.color.a=1.0f;
      paths.push_back(path9);



//  //generate scene boundries markers
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

