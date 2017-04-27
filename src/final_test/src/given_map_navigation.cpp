/* this scene is the standard giving scene described in config/given_map_altofer.xml
 * this is a temporary demo so there's no convenient setup module in launch file. You can only change the scene or way
 * point by rebuild the whole package.
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
//std::vector<visualization_msgs::Marker> scene_marker;

int main(int argc, char **argv)
{
  //data for parameters
  int scene_data[4];//left, top, width, height
  int waypoint[4];//x1, y1, r1,x2, y2, r2


  ros::init(argc, argv, "pedsim_demo");
  ros::NodeHandle nh("~");
  ros::Publisher path_pub=nh.advertise<visualization_msgs::Marker>("path",20);
  ros::Publisher scene_pub=nh.advertise<visualization_msgs::Marker>("scene",20);
  ros::Rate r(5);

  //this is designed to let the publisher wait for the subscriber be ready.
  while(scene_pub.getNumSubscribers()<1){
    if(!ros::ok())  return 0;
    ROS_WARN_ONCE("Please create a subscriber to the maker");
    sleep(1);
  }


  // initiate markers
  marker_initiate(paths,5);

  //----------------Pedsim initiate---------------------


  //set the scene
  Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);
  //create the scene Markers
  set_scene_boundry(scene_pub,pedscene,boundry,9 ); //create the scene Markers
  /* -----*-----------------------------*-------
 *      -------------------------------
 * -----*-----------------------------*-------
 * top,down,left,right,radius*/
  Ped::Twaypoint *w1 =  new Ped::Twaypoint(waypoint[2],waypoint[0],waypoint[4]);
  Ped::Twaypoint *w2 =  new Ped::Twaypoint(waypoint[2],waypoint[1],waypoint[4]);
  Ped::Twaypoint *w4 =  new Ped::Twaypoint(waypoint[3],waypoint[0],waypoint[4]);
  Ped::Twaypoint *w3 =  new Ped::Twaypoint(waypoint[3],waypoint[1],waypoint[4]);
  int pos=2;
  for (int i=0;i<10;i++){
    Ped::Tagent *a =new Ped::Tagent();
    a->addWaypoint(w1);
    a->addWaypoint(w2);
    a->addWaypoint(w3);
    a->addWaypoint(w4);

    a->setPosition(0,pos+=1,0);

    pedscene->addAgent(a);
  }

  //Get another robot agent working
  Ped::Tagent *robot = new Ped::Tagent();
  Ped::Twaypoint *w5 =  new Ped::Twaypoint(10,18,5);
  Ped::Twaypoint *w6 =  new Ped::Twaypoint(10,-18,5);
  robot->addWaypoint(w5);
  robot->addWaypoint(w6);
  robot->setPosition(10,0,0);
  pedscene->addAgent(robot);
  //set obstacle, middle obstacle
  //  set_obstacle(scene_pub,pedscene,(waypoint[0]+waypoint[1])/2,(waypoint[0]+waypoint[1])/2,waypoint[2],waypoint[3]);

  //set baundry
  set_scene_boundry(scene_pub,pedscene,scene_data[0],scene_data[1],scene_data[2],scene_data[3]);


  while(nh.ok()){
    pedscene->moveAgents(0.5);
    draw_path(paths,pedscene);
    for(std::vector<visualization_msgs::Marker>::iterator it=paths.begin();it!=paths.end();++it)
      path_pub.publish(*it);
    r.sleep();
  }

  //clean up the mess, free the memory
  for (Ped::Tagent * agent :pedscene->getAllAgents()) delete agent;
  delete pedscene;
  delete w1;
  delete w2;
  //    delete o;
  delete robot;


  ROS_INFO("Hello world!");
}
