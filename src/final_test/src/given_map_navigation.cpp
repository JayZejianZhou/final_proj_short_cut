/* this scene is the standard giving scene described in config/given_map_altofer.xml
 * this is a temporary demo so there's no convenient setup module in launch file. You can only change the scene or way
 * point by rebuild the whole package.
 *
 * The fucking room is too complicated that the rosnode cannot handle.
 */

#include <ros/ros.h>
#include <pedsim/ped_scene.h>
#include <pedsim/ped_waypoint.h>
#include <pedsim/ped_outputwriter.h>
#include <pedsim/ped_obstacle.h>
#include <ros/time.h>
#include <ped_marker.h>
#include <vector>
#include <visualization_msgs/Marker.h>
#include <navigation.h>


//given agent number,11 maximum
#define AGENT_NUM 4

//set polygon boundries,left,top,right,down
  double boundry[36]={ 0,   40,   0,   0,
                       0,   40,  20,  40,
                       20,  40,  20,   0 ,
                       0,    0,  20,0,
                       0,30,15,30,
                       5,20,20,20,
                       0,15,5,15,
                       10,15,15,15,
                       5,10,15,10
                     };


std::vector<visualization_msgs::Marker> paths;
std::vector<Ped::Twaypoint*> waypoints;
std::vector<visualization_msgs::Marker> agents;

//std::vector<visualization_msgs::Marker> scene_marker;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pedsim_demo");
  std::cout<<"0~";

  ros::NodeHandle nh;
  ros::Publisher path_pub=nh.advertise<visualization_msgs::Marker>("path",20);
  ros::Publisher scene_pub=nh.advertise<visualization_msgs::Marker>("scene",20);
  ros::Publisher o_path_pub=nh.advertise<visualization_msgs::Marker>("path_o",20);
  ros::Publisher agent_pub=nh.advertise<visualization_msgs::Marker>("agent",20);

  ros::Rate r(2);
  std::cout<<'0';
  //this is designed to let the publisher wait for the subscriber be ready.
  while(scene_pub.getNumSubscribers()<1){
    if(!ros::ok())  return 0;
    ROS_WARN_ONCE("Please create a subscriber to the maker");
    sleep(1);
  }
  std::cout<<".0\n\n\n";
  //initiate agents markers
  show_agents(agent_pub,agents);
  for (std::vector<visualization_msgs::Marker>::iterator it=agents.begin();it<agents.end();it++)
    agent_pub.publish(*it);

  // initiate markers
  marker_initiate(paths,4);


//  navigation init
  Navigation na(0,40,20,0,3,3,3,37);//don't forget 2 pixel offset
  na.navigate(boundry,waypoints);

  std::cout<<"1\n\n\n";




//  //----------------Pedsim initiate---------------------
  //set the scene
  Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);
  //create the scene Markers
  set_scene_boundry(scene_pub,pedscene,boundry,9 ); //create the scene Markers
  /* -----*-----------------------------*-------
 *      -------------------------------
 * -----*-----------------------------*-------
 * top,down,left,right,radius*/
  Ped::Twaypoint *w1 =  new Ped::Twaypoint(2,13,0.5);
  Ped::Twaypoint *w2 =  new Ped::Twaypoint(18,13,0.5);

  Ped::Twaypoint *w3 =  new Ped::Twaypoint(2,17,0.5);
  Ped::Twaypoint *w4 =  new Ped::Twaypoint(18,17,0.5);

  Ped::Twaypoint *w5 =  new Ped::Twaypoint(2,25,0.5);
  Ped::Twaypoint *w6 =  new Ped::Twaypoint(18,25,0.5);

  std::cout<<"2\n\n\n";
  int pos=-7;
  Ped::Tagent *a1 =new Ped::Tagent();
  a1->addWaypoint(w1);
  a1->addWaypoint(w2);
  a1->setPosition(1,13,0);
  pedscene->addAgent(a1);

  Ped::Tagent *a2 =new Ped::Tagent();
  a2->addWaypoint(w4);
  a2->addWaypoint(w3);
  a2->setPosition(19,17,0);
  pedscene->addAgent(a2);

  Ped::Tagent *a3 =new Ped::Tagent();
  a3->addWaypoint(w5);
  a3->addWaypoint(w6);
  a3->setPosition(1,25,0);
  pedscene->addAgent(a3);
  std::cout<<"3\n\n\n";


  //    Get another robot agent working
  Ped::Tagent *robot_o = new Ped::Tagent();
  for(std::vector<Ped::Twaypoint*>::iterator it=waypoints.begin();it<waypoints.end();it++)
    robot_o->addWaypoint(*it);
  robot_o->setPosition(na.m.start_x,na.m.start_y,0);
  pedscene->addAgent(robot_o);
  std::cout<<'4';
  //try to show the original robot's path
  visualization_msgs::Marker pathR;
  pathR.header.frame_id="/map";
  pathR.header.stamp=ros::Time::now();
  pathR.ns="path2";
  pathR.id=2;// 0---based
  pathR.action=visualization_msgs::Marker::ADD;
  pathR.type=visualization_msgs::Marker::LINE_STRIP;
  pathR.scale.x=0.1;
  pathR.color.r=0;
  pathR.color.g=1;
  pathR.color.b=0;
  pathR.color.a=1.0f;
  for(std::vector<Ped::Twaypoint*>::iterator it=waypoints.begin();it<waypoints.end();it++){
    geometry_msgs::Point p;
    p.x=(*it)->getx();
    p.y=(*it)->gety();
    p.z=0;
   pathR.points.push_back(p);
  }
  o_path_pub.publish(pathR);
  int count=0;//run count

  while(nh.ok()){
        pedscene->moveAgents(0.4);
        draw_path(paths,pedscene,agents);//TODO:resubscribe agents in rviz will cause faliour
        for(std::vector<visualization_msgs::Marker>::iterator it=paths.begin();it!=paths.end();++it)
          path_pub.publish(*it);
        for(std::vector<visualization_msgs::Marker>::iterator it=agents.begin();it!=agents.end();++it)
          agent_pub.publish(*it);
    r.sleep();
  }

  //clean up the mess, free the memory
  for (Ped::Tagent * agent :pedscene->getAllAgents()) delete agent;
  delete pedscene;
  //  delete w1;agents
  //  delete w2;
  //    delete o;
  //  delete robot;


  ROS_INFO("Hello world!");
}
