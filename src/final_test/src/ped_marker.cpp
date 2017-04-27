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
#include <math.h>


//initiate those paths, 11 maximum (a vector of Marker, number of markers)
void marker_initiate(std::vector<visualization_msgs::Marker> &paths, int num){
  if(num>12)
    std::cout<<"Too many agents. Maximum is 11\n";

  //generating path markers without a loop
  if(num>=1){
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
  }
  if(num>=2){
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
  }
  if(num>=3){
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
  }
  if(num>=4){
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
  }
  if(num>=5){
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
  }
  if(num>=6){
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
  }
  if(num>=7){
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
  }
  if(num>=8){
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
  }
  if(num>=9){
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
  }
  if(num>=10){
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
  }
  if(num>=11){
      visualization_msgs::Marker pathr;
      pathr.header.frame_id="/map";
      pathr.header.stamp=ros::Time::now();
      pathr.ns="path9";
      pathr.id=10;// 0---based
      pathr.action=visualization_msgs::Marker::ADD;
      pathr.type=visualization_msgs::Marker::LINE_STRIP;
      pathr.scale.x=0.1;
      pathr.color.r=1;
      pathr.color.g=0;
      pathr.color.b=0;
      pathr.color.a=1.0f;
      paths.push_back(pathr);
}
  //generate scene boundries markers
//  for(int i=0;i<num;i++){
//    visualization_msgs::Marker *scene= new visualization_msgs::Marker();
//    scene->header.frame_id="/map";
//    scene->header.stamp=ros::Time::now();
//    scene->ns="path";
//    scene->id=i;// 0---based
//    scene->action=visualization_msgs::Marker::ADD;
//    scene->type=visualization_msgs::Marker::LINE_STRIP;
//    scene->scale.x=0.5;
//    scene->color.r=1;
//    scene->color.g=0;
//    scene->color.b=0;
//    scene->color.a=1.0f;
//    paths.push_back(*scene);
//  }
}

//this function draw paths for every agent
void draw_path(std::vector<visualization_msgs::Marker> &paths, Ped::Tscene *scene){
  for(Ped::Tagent* agent : scene->getAllAgents()){
    geometry_msgs::Point p;
    p.x=agent->getPosition().x;
    p.y=agent->getPosition().y;
    p.z=0;
//        std::cout<<agent->getid()<<' '<<agent->getPosition().x<<' '<<agent->getPosition().y<<'\n';
    //    std::cout<<agent->getid()<<'\n';
    //    if(agent->getid()==0)
    paths[agent->getid()].points.push_back(p);
  }
//  std::cout<<"number of agents:"<<paths.size()<<'\n';
}

// read in parameters from XML file
void read_in_param(ros::NodeHandle & nh, int *scene_data, int *waypoint,double speed){
  nh.param<int>("scene_top",scene_data[0],100);
  nh.param<int>("scene_down",scene_data[1],-100);
  nh.param<int>("scene_left",scene_data[2],-100);
  nh.param<int>("scene_right",scene_data[3],100);

  nh.param<int>("waypoint_top",waypoint[0],50);
  nh.param<int>("waypoint_down",waypoint[1],-50);
  nh.param<int>("waypoint_left",waypoint[2],-50);
  nh.param<int>("waypoint_right",waypoint[3],50);
  nh.param<int>("waypoint_radius",waypoint[4],10);

  nh.param<double>("walk_speed",speed,0.5);
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
  obs.scale.x=(right-left);
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

//set scene boundry in a rectangle shape
void set_scene_boundry(ros::Publisher & scene_pub,Ped::Tscene * pedscene, int top, int down, int left, int right){
  //set the visualization left boundry
  visualization_msgs::Marker boundry_left;
  boundry_left.header.frame_id="/map";
  boundry_left.header.stamp=ros::Time::now();
  boundry_left.ns="scene_boundry";
  boundry_left.id=0;
  boundry_left.action=visualization_msgs::Marker::ADD;
  boundry_left.type=visualization_msgs::Marker::CUBE;
  boundry_left.pose.position.x=left;
  boundry_left.pose.position.y=(top+down)/2;
  boundry_left.pose.position.z=0;
  boundry_left.pose.orientation.x=0;
  boundry_left.pose.orientation.y=0;
  boundry_left.pose.orientation.z=0;
  boundry_left.pose.orientation.w=0;
  boundry_left.scale.x=1;
  boundry_left.scale.y=(top-down);
  boundry_left.scale.z=4.0;
  boundry_left.color.r=1.0f;
  boundry_left.color.g=0.0f;
  boundry_left.color.b=0.0f;
  boundry_left.color.a=1.0;
  boundry_left.lifetime=ros::Duration();
  scene_pub.publish(boundry_left);


  //set the visualization right boundry
  visualization_msgs::Marker boundry_right;
  boundry_right.header.frame_id="/map";
  boundry_right.header.stamp=ros::Time::now();
  boundry_right.ns="scene_boundry";
  boundry_right.id=1;
  boundry_right.action=visualization_msgs::Marker::ADD;
  boundry_right.type=visualization_msgs::Marker::CUBE;
  boundry_right.pose.position.x=right;
  boundry_right.pose.position.y=(top+down)/2;
  boundry_right.pose.position.z=0;
  boundry_right.pose.orientation.x=0;
  boundry_right.pose.orientation.y=0;
  boundry_right.pose.orientation.z=0;
  boundry_right.pose.orientation.w=0;
  boundry_right.scale.x=1;
  boundry_right.scale.y=(top-down);
  boundry_right.scale.z=4.0;
  boundry_right.color.r=1.0f;
  boundry_right.color.g=0.0f;
  boundry_right.color.b=0.0f;
  boundry_right.color.a=1.0;
  boundry_right.lifetime=ros::Duration();
  scene_pub.publish(boundry_right);

  //set the visualization right boundry
  visualization_msgs::Marker boundry_top;
  boundry_top.header.frame_id="/map";
  boundry_top.header.stamp=ros::Time::now();
  boundry_top.ns="scene_boundry";
  boundry_top.id=2;
  boundry_top.action=visualization_msgs::Marker::ADD;
  boundry_top.type=visualization_msgs::Marker::CUBE;
  boundry_top.pose.position.x=(left+right)/2;
  boundry_top.pose.position.y=top;
  boundry_top.pose.position.z=0;
  boundry_top.pose.orientation.x=0;
  boundry_top.pose.orientation.y=0;
  boundry_top.pose.orientation.z=0;
  boundry_top.pose.orientation.w=0;
  boundry_top.scale.x=(right-left);
  boundry_top.scale.y=1;
  boundry_top.scale.z=4.0;
  boundry_top.color.r=1.0f;
  boundry_top.color.g=0.0f;
  boundry_top.color.b=0.0f;
  boundry_top.color.a=1.0;
  boundry_top.lifetime=ros::Duration();
  scene_pub.publish(boundry_top);

  visualization_msgs::Marker boundry_down;
  boundry_down.header.frame_id="/map";
  boundry_down.header.stamp=ros::Time::now();
  boundry_down.ns="scene_boundry";
  boundry_down.id=3;
  boundry_down.action=visualization_msgs::Marker::ADD;
  boundry_down.type=visualization_msgs::Marker::CUBE;
  boundry_down.pose.position.x=(left+right)/2;
  boundry_down.pose.position.y=down;
  boundry_down.pose.position.z=0;
  boundry_down.pose.orientation.x=0;
  boundry_down.pose.orientation.y=0;
  boundry_down.pose.orientation.z=0;
  boundry_down.pose.orientation.w=0;
  boundry_down.scale.x=(right-left);
  boundry_down.scale.y=1;
  boundry_down.scale.z=4.0;
  boundry_down.color.r=1.0f;
  boundry_down.color.g=0.0f;
  boundry_down.color.b=0.0f;
  boundry_down.color.a=1.0;
  boundry_down.lifetime=ros::Duration();
  scene_pub.publish(boundry_down);


  //set the scene_boundry in pedsim

    Ped::Tobstacle *boundry_left_o = new Ped::Tobstacle(left,top,left,down);
     pedscene->addObstacle(boundry_left_o);

  Ped::Tobstacle *boundry_right_o = new Ped::Tobstacle(right,top,right,down);
  pedscene->addObstacle(boundry_right_o);

  Ped::Tobstacle *boundry_top_o = new Ped::Tobstacle(left,top,right,top);
  pedscene->addObstacle(boundry_top_o);

  Ped::Tobstacle *boundry_down_o = new Ped::Tobstacle(left,down,right,down);
  pedscene->addObstacle(boundry_down_o);


  //--------------Example test---------
//  Ped::Tobstacle *o = new Ped::Tobstacle(-20, -50,  -20, +50);
//   pedscene->addObstacle(o);
}

//overwrite the set scene function in polygon shape, maximum 11
void set_scene_boundry(ros::Publisher &scene_pub, Ped::Tscene *pedscene, double boundry[36], int number){
  for(int i=0;i<number;i++){
    visualization_msgs::Marker scene1;
    scene1.header.frame_id="/map";
    scene1.header.stamp=ros::Time::now();
    scene1.ns="scene_boundry_rectangle";
    scene1.id=i;
    scene1.action=visualization_msgs::Marker::ADD;
    scene1.type=visualization_msgs::Marker::CUBE;
    scene1.pose.position.x=(boundry[4*i]+boundry[4*i+2])/2;
    scene1.pose.position.y=(boundry[4*i+1]+boundry[4*i+3])/2;
    scene1.pose.position.z=0;
    scene1.pose.orientation.x=0;
    scene1.pose.orientation.y=0;
    scene1.pose.orientation.z=0;
    scene1.pose.orientation.w=0;
    scene1.scale.x=fmax(0.2,fabs(boundry[4*i+0]-boundry[4*i+2]));
    scene1.scale.y=fmax(0.2,fabs(boundry[4*i+1]-boundry[4*i+3]));
    scene1.scale.z=2.0;
    scene1.color.r=1.0f;
    scene1.color.g=0.0f;
    scene1.color.b=0.0f;
    scene1.color.a=1.0;
    scene1.lifetime=ros::Duration();
    scene_pub.publish(scene1);
  }
//  if(number>11){
//    std::cout<<"Too many edges, maximum 10"<<std::endl;
//    return;
//  }
//  if(number>=1){
//    visualization_msgs::Marker scene1;
//    scene1.header.frame_id="/map";
//    scene1.header.stamp=ros::Time::now();
//    scene1.ns="scene_boundry_rectangle";
//    scene1.id=0;
//    scene1.action=visualization_msgs::Marker::ADD;
//    scene1.type=visualization_msgs::Marker::CUBE;
//    scene1.pose.position.x=(boundry[0]+boundry[2])/2;
//    scene1.pose.position.y=(boundry[1]+boundry[3])/2;
//    scene1.pose.position.z=0;
//    scene1.pose.orientation.x=0;
//    scene1.pose.orientation.y=0;
//    scene1.pose.orientation.z=0;
//    scene1.pose.orientation.w=0;
//    scene1.scale.x=fmax(0.2,fabs(boundry[0]-boundry[2]));
//    scene1.scale.y=fmax(0.2,fabs(boundry[1]-boundry[3]));
//    scene1.scale.z=2.0;
//    scene1.color.r=1.0f;
//    scene1.color.g=0.0f;
//    scene1.color.b=0.0f;
//    scene1.color.a=1.0;
//    scene1.lifetime=ros::Duration();
//    scene_pub.publish(scene1);
//  }
//  if(number>=2){
//    visualization_msgs::Marker scene2;
//    scene2.header.frame_id="/map";
//    scene2.header.stamp=ros::Time::now();
//    scene2.ns="scene_boundry_rectangle";
//    scene2.id=1;
//    scene2.action=visualization_msgs::Marker::ADD;
//    scene2.type=visualization_msgs::Marker::CUBE;
//    scene2.pose.position.x=(left+right)/2;
//    scene2.pose.position.y=down;
//    scene2.pose.position.z=0;
//    scene2.pose.orientation.x=0;
//    scene2.pose.orientation.y=0;
//    scene2.pose.orientation.z=0;
//    scene2.pose.orientation.w=0;
//    scene2.scale.x=(right-left);
//    scene2.scale.y=1;
//    scene2.scale.z=4.0;
//    scene2.color.r=1.0f;
//    scene2.color.g=0.0f;
//    scene2.color.b=0.0f;
//    scene2.color.a=1.0;
//    scene2.lifetime=ros::Duration();
//    scene_pub.publish(scene2);
//  }
//  if(number>=3){
//    visualization_msgs::Marker scene3;
//    scene3.header.frame_id="/map";
//    scene3.header.stamp=ros::Time::now();
//    scene3.ns="scene_boundry_rectangle";
//    scene3.id=2;
//    scene3.action=visualization_msgs::Marker::ADD;
//    scene3.type=visualization_msgs::Marker::CUBE;
//    scene3.pose.position.x=(left+right)/2;
//    scene3.pose.position.y=down;
//    scene3.pose.position.z=0;
//    scene3.pose.orientation.x=0;
//    scene3.pose.orientation.y=0;
//    scene3.pose.orientation.z=0;
//    scene3.pose.orientation.w=0;
//    scene3.scale.x=(right-left);
//    scene3.scale.y=1;
//    scene3.scale.z=4.0;
//    scene3.color.r=1.0f;
//    scene3.color.g=0.0f;
//    scene3.color.b=0.0f;
//    scene3.color.a=1.0;
//    scene3.lifetime=ros::Duration();
//    scene_pub.publish(scene3);
//  }
//  if(number>=4){
//    visualization_msgs::Marker scene4;
//    scene4.header.frame_id="/map";
//    scene4.header.stamp=ros::Time::now();
//    scene4.ns="scene_boundry_rectangle";
//    scene4.id=3;
//    scene4.action=visualization_msgs::Marker::ADD;
//    scene4.type=visualization_msgs::Marker::CUBE;
//    scene4.pose.position.x=(left+right)/2;
//    scene4.pose.position.y=down;
//    scene4.pose.position.z=0;
//    scene4.pose.orientation.x=0;
//    scene4.pose.orientation.y=0;
//    scene4.pose.orientation.z=0;
//    scene4.pose.orientation.w=0;
//    scene4.scale.x=(right-left);
//    scene4.scale.y=1;
//    scene4.scale.z=4.0;
//    scene4.color.r=1.0f;
//    scene4.color.g=0.0f;
//    scene4.color.b=0.0f;
//    scene4.color.a=1.0;
//    scene4.lifetime=ros::Duration();
//    scene_pub.publish(scene4);
//  }
//  if(number>=5){
//    visualization_msgs::Marker scene5;
//    scene5.header.frame_id="/map";
//    scene5.header.stamp=ros::Time::now();
//    scene5.ns="scene_boundry_rectangle";
//    scene5.id=4;
//    scene5.action=visualization_msgs::Marker::ADD;
//    scene5.type=visualization_msgs::Marker::CUBE;
//    scene5.pose.position.x=(left+right)/2;
//    scene5.pose.position.y=down;
//    scene5.pose.position.z=0;
//    scene5.pose.orientation.x=0;
//    scene5.pose.orientation.y=0;
//    scene5.pose.orientation.z=0;
//    scene5.pose.orientation.w=0;
//    scene5.scale.x=(right-left);
//    scene5.scale.y=1;
//    scene5.scale.z=4.0;
//    scene5.color.r=1.0f;
//    scene5.color.g=0.0f;
//    scene5.color.b=0.0f;
//    scene5.color.a=1.0;
//    scene5.lifetime=ros::Duration();
//    scene_pub.publish(scene5);
//  }
//  if(number>=6){
//    visualization_msgs::Marker scene6;
//    scene6.header.frame_id="/map";
//    scene6.header.stamp=ros::Time::now();
//    scene6.ns="scene_boundry_rectangle";
//    scene6.id=5;
//    scene6.action=visualization_msgs::Marker::ADD;
//    scene6.type=visualization_msgs::Marker::CUBE;
//    scene6.pose.position.x=(left+right)/2;
//    scene6.pose.position.y=down;
//    scene6.pose.position.z=0;
//    scene6.pose.orientation.x=0;
//    scene6.pose.orientation.y=0;
//    scene6.pose.orientation.z=0;
//    scene6.pose.orientation.w=0;
//    scene6.scale.x=(right-left);
//    scene6.scale.y=1;
//    scene6.scale.z=4.0;
//    scene6.color.r=1.0f;
//    scene6.color.g=0.0f;
//    scene6.color.b=0.0f;
//    scene6.color.a=1.0;
//    scene6.lifetime=ros::Duration();
//    scene_pub.publish(scene6);
//  }
//  if(number>=7){
//    visualization_msgs::Marker scene7;
//    scene7.header.frame_id="/map";
//    scene7.header.stamp=ros::Time::now();
//    scene7.ns="scene_boundry_rectangle";
//    scene7.id=6;
//    scene7.action=visualization_msgs::Marker::ADD;
//    scene7.type=visualization_msgs::Marker::CUBE;
//    scene7.pose.position.x=(left+right)/2;
//    scene7.pose.position.y=down;
//    scene7.pose.position.z=0;
//    scene7.pose.orientation.x=0;
//    scene7.pose.orientation.y=0;
//    scene7.pose.orientation.z=0;
//    scene7.pose.orientation.w=0;
//    scene7.scale.x=(right-left);
//    scene7.scale.y=1;
//    scene7.scale.z=4.0;
//    scene7.color.r=1.0f;
//    scene7.color.g=0.0f;
//    scene7.color.b=0.0f;
//    scene7.color.a=1.0;
//    scene7.lifetime=ros::Duration();
//    scene_pub.publish(scene7);
//  }
//  if(number>=8){
//    visualization_msgs::Marker scene8;
//    scene8.header.frame_id="/map";
//    scene8.header.stamp=ros::Time::now();
//    scene8.ns="scene_boundry_rectangle";
//    scene8.id=7;
//    scene8.action=visualization_msgs::Marker::ADD;
//    scene8.type=visualization_msgs::Marker::CUBE;
//    scene8.pose.position.x=(left+right)/2;
//    scene8.pose.position.y=down;
//    scene8.pose.position.z=0;
//    scene8.pose.orientation.x=0;
//    scene8.pose.orientation.y=0;
//    scene8.pose.orientation.z=0;
//    scene8.pose.orientation.w=0;
//    scene8.scale.x=(right-left);
//    scene8.scale.y=1;
//    scene8.scale.z=4.0;
//    scene8.color.r=1.0f;
//    scene8.color.g=0.0f;
//    scene8.color.b=0.0f;
//    scene8.color.a=1.0;
//    scene8.lifetime=ros::Duration();
//    scene_pub.publish(scene8);
//  }
//  if(number>=9){
//    visualization_msgs::Marker scene9;
//    scene9.header.frame_id="/map";
//    scene9.header.stamp=ros::Time::now();
//    scene9.ns="scene_boundry_rectangle";
//    scene9.id=8;
//    scene9.action=visualization_msgs::Marker::ADD;
//    scene9.type=visualization_msgs::Marker::CUBE;
//    scene9.pose.position.x=(left+right)/2;
//    scene9.pose.position.y=down;
//    scene9.pose.position.z=0;
//    scene9.pose.orientation.x=0;
//    scene9.pose.orientation.y=0;
//    scene9.pose.orientation.z=0;
//    scene9.pose.orientation.w=0;
//    scene9.scale.x=(right-left);
//    scene9.scale.y=1;
//    scene9.scale.z=4.0;
//    scene9.color.r=1.0f;
//    scene9.color.g=0.0f;
//    scene9.color.b=0.0f;
//    scene9.color.a=1.0;
//    scene9.lifetime=ros::Duration();
//    scene_pub.publish(scene9);
//  }
//  if(number>=10){
//    visualization_msgs::Marker scene10;
//    scene10.header.frame_id="/map";
//    scene10.header.stamp=ros::Time::now();
//    scene10.ns="scene_boundry_rectangle";
//    scene10.id=9;
//    scene10.action=visualization_msgs::Marker::ADD;
//    scene10.type=visualization_msgs::Marker::CUBE;
//    scene10.pose.position.x=(left+right)/2;
//    scene10.pose.position.y=down;
//    scene10.pose.position.z=0;
//    scene10.pose.orientation.x=0;
//    scene10.pose.orientation.y=0;
//    scene10.pose.orientation.z=0;
//    scene10.pose.orientation.w=0;
//    scene10.scale.x=(right-left);
//    scene10.scale.y=1;
//    scene10.scale.z=4.0;
//    scene10.color.r=1.0f;
//    scene10.color.g=0.0f;
//    scene10.color.b=0.0f;
//    scene10.color.a=1.0;
//    scene10.lifetime=ros::Duration();
//    scene_pub.publish(scene10);
//  }
//  if(number>=11){
//    visualization_msgs::Marker scene11;
//    scene11.header.frame_id="/map";
//    scene11.header.stamp=ros::Time::now();
//    scene11.ns="scene_boundry_rectangle";
//    scene11.id=10;
//    scene11.action=visualization_msgs::Marker::ADD;
//    scene11.type=visualization_msgs::Marker::CUBE;
//    scene11.pose.position.x=(left+right)/2;
//    scene11.pose.position.y=down;
//    scene11.pose.position.z=0;
//    scene11.pose.orientation.x=0;
//    scene11.pose.orientation.y=0;
//    scene11.pose.orientation.z=0;
//    scene11.pose.orientation.w=0;
//    scene11.scale.x=(right-left);
//    scene11.scale.y=1;
//    scene11.scale.z=4.0;
//    scene11.color.r=1.0f;
//    scene11.color.g=0.0f;
//    scene11.color.b=0.0f;
//    scene11.color.a=1.0;
//    scene11.lifetime=ros::Duration();
//    scene_pub.publish(scene11);
//  }
}

