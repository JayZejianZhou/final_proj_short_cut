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
double boundry[36]={ 0,   0,   0,   -8.5,
                     0,   -8.5,7.5, -8.5,
                     7.5, -8.5,7.5, -2.5,
                     7.5, -2.5,13,  -2.5,
                     13,  -2.5,13,  -5.0,
                     13,  -5.0,15.5,-5.0,
                     15.5,-5.0,15.5,0,
                     15.5,0,   0,   0,
                     0,   -2.5,5.5, -2.5};


std::vector<visualization_msgs::Marker> paths;
std::vector<Ped::Twaypoint*> waypoints;

//std::vector<visualization_msgs::Marker> scene_marker;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pedsim_demo");
  std::cout<<"0~";

  ros::NodeHandle nh;
  ros::Publisher path_pub=nh.advertise<visualization_msgs::Marker>("path",20);
  ros::Publisher scene_pub=nh.advertise<visualization_msgs::Marker>("scene",20);
  ros::Rate r(2);
  std::cout<<'0';
  //this is designed to let the publisher wait for the subscriber be ready.
  while(scene_pub.getNumSubscribers()<1){
    if(!ros::ok())  return 0;
    ROS_WARN_ONCE("Please create a subscriber to the maker");
    sleep(1);
  }
  std::cout<<".0";

  // initiate markers
  marker_initiate(paths,4);


  //navigation init
  Navigation na(0,0,19,-10,1,-7,14,-2);
  na.navigate(boundry,waypoints);

  std::cout<<'1';




  //----------------Pedsim initiate---------------------
  //set the scene
  Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);
  //create the scene Markers
  set_scene_boundry(scene_pub,pedscene,boundry,9 ); //create the scene Markers
  /* -----*-----------------------------*-------
 *      -------------------------------
 * -----*-----------------------------*-------
 * top,down,left,right,radius*/
  Ped::Twaypoint *w1 =  new Ped::Twaypoint(1,-7,0.5);
  Ped::Twaypoint *w2 =  new Ped::Twaypoint(6,-3,0.5);
  std::cout<<'2';
  int pos=-7;
  Ped::Tagent *a1 =new Ped::Tagent();
  a1->addWaypoint(w1);
  a1->addWaypoint(w2);
  a1->setPosition(4,pos+=1,0);
  pedscene->addAgent(a1);

  Ped::Tagent *a2 =new Ped::Tagent();
  a2->addWaypoint(w1);
  a2->addWaypoint(w2);
  a2->setPosition(4,pos+=1,0);
  pedscene->addAgent(a2);

  Ped::Tagent *a3 =new Ped::Tagent();
  a3->addWaypoint(w1);
  a3->addWaypoint(w2);
  a3->setPosition(4,pos+=1,0);
  pedscene->addAgent(a3);
  std::cout<<'3';
  //    Get another robot agent working
  Ped::Tagent *robot_o = new Ped::Tagent();
  for(std::vector<Ped::Twaypoint*>::iterator it=waypoints.begin();it<waypoints.end();it++)
    robot_o->addWaypoint(*it);
  robot_o->setPosition(1,-6,0);
  pedscene->addAgent(robot_o);
  std::cout<<'4';

  int count=0;//run count
  while(nh.ok()){
        pedscene->moveAgents(0.2);
        draw_path(paths,pedscene);
        for(std::vector<visualization_msgs::Marker>::iterator it=paths.begin();it!=paths.end();++it)
          path_pub.publish(*it);
    r.sleep();
  }

  //clean up the mess, free the memory
  for (Ped::Tagent * agent :pedscene->getAllAgents()) delete agent;
  delete pedscene;
  //  delete w1;
  //  delete w2;
  //    delete o;
  //  delete robot;


  ROS_INFO("Hello world!");
}
