#include <ros/ros.h>
//#include <libpedsim/ped_includes.h>
//#include <libpedsim/ped_outputwriter.h>
//#include <libpedsim/ped_scene.h>
#include <pedsim/ped_scene.h>
#include <pedsim/ped_waypoint.h>
#include <pedsim/ped_outputwriter.h>
#include <pedsim/ped_obstacle.h>
#include <ros/time.h>
#include <ped_marker.h>
#include <vector>
#include <visualization_msgs/Marker.h>

#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/GetGridMap.h>



std::vector<visualization_msgs::Marker> paths;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pedsim");
  ros::NodeHandle nh;
  ros::Publisher path_pub=nh.advertise<visualization_msgs::Marker>("path",20);
  ros::Rate r(1);
  marker_initiate(paths);

  //-----------------this is a simple test---------------------
  //create output writer
  Ped::OutputWriter *ow = new Ped::FileOutputWriter();
  ow->setScenarioName("Example_self 01");

  Ped::Tscene *pedscene = new Ped::Tscene(-10,-10,40,40);
  pedscene->setOutputWriter(ow);

   Ped::Twaypoint *w1 =  new Ped::Twaypoint(0,0,0);
   Ped::Twaypoint *w2 =  new Ped::Twaypoint(10,10,12);

 // Ped::Tobstacle *o = new Ped::Tobstacle(0,-50,0,+50);
 // pedscene->addObstacle(o);
  int pos=0;
  for (int i=0;i<10;i++){
    Ped::Tagent *a =new Ped::Tagent();
  //  a->addWaypoint(w1);
    a->addWaypoint(w2);

    a->setPosition(0,pos++,0);

    pedscene->addAgent(a);
  }

  while(nh.ok()){
      pedscene->moveAgents(1.0);
      draw_path(paths,pedscene);
      for(std::vector<visualization_msgs::Marker>::iterator it=paths.begin();it!=paths.end();++it)
        path_pub.publish(*it);
      r.sleep();
  }
  for (Ped::Tagent * agent :pedscene->getAllAgents()) delete agent;
    delete pedscene;
    delete w1;
    delete w2;
//    delete o;
    delete ow;


  ROS_INFO("Hello world!");
}
