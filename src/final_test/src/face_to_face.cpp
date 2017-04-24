/* this scene should look like this
 * ----------------------------------------------------------  /length is 20
 *
 *                                                             // width is 5
 *           *(4,2)                             *(16,2)        //two agents face to face.
 *
 *
 *
 *--------------------------------------------------------------
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




std::vector<visualization_msgs::Marker> paths;
//std::vector<visualization_msgs::Marker> scene_marker;

int main(int argc, char **argv)
{
  //data for parameters
  int scene_data[4];//corresponding to parameteres set in launch file
  int waypoint[4];//
  double speed;


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

  // initiate markers, Let's get 2 agents
  marker_initiate(paths,2);

  //----------------Pedsim initiate---------------------
  //create output writer, default output of pedsim library, useful for debagging
  Ped::OutputWriter *ow = new Ped::FileOutputWriter();
  ow->setScenarioName("face_to_face_log");

  //scene parameter process
  read_in_param(nh,scene_data,waypoint,speed);

  //set the scene, make the scene to be as large as possible for agents to prevent exceeding
  Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);
  pedscene->setOutputWriter(ow);
  Ped::Twaypoint *w1 =  new Ped::Twaypoint(waypoint[2],waypoint[0],waypoint[4]);
  Ped::Twaypoint *w2 =  new Ped::Twaypoint(waypoint[3],waypoint[0],waypoint[4]);

  //set the first agent
  Ped::Tagent *left=new Ped::Tagent();
  left->addWaypoint(w1);
  left->addWaypoint(w2);
  left->setPosition(waypoint[3],waypoint[0],0);
  pedscene->addAgent(left);

  //set the second agent
  Ped::Tagent *right=new Ped::Tagent();
  right->addWaypoint(w2);
  right->addWaypoint(w1);
  right->setPosition(waypoint[2],waypoint[0],0);
  pedscene->addAgent(right);

  //set baundry
  set_scene_boundry(scene_pub,pedscene,scene_data[0],scene_data[1],scene_data[2],scene_data[3]);

  //main node loop
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
  delete ow;
}
