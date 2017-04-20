#include <ros/ros.h>
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
//std::vector<visualization_msgs::Marker> scene_marker;

int main(int argc, char **argv)
{
  //data for parameters
  int scene_data[4];//left, top, width, height
  int waypoint[4];//x1, y1, r1,x2, y2, r2


  ros::init(argc, argv, "pedsim_demo");
  ros::NodeHandle nh("~");
  ros::Publisher path_pub=nh.advertise<visualization_msgs::Marker>("path",20);
//  ros::Publisher publisher = nh.advertise<grid_map_msgs::GridMap>("grid_map", 1, true);
  ros::Publisher scene_pub=nh.advertise<visualization_msgs::Marker>("scene",20);
  ros::Rate r(5);

  //this is designed to let the publisher wait for the subscriber be ready.
  while(scene_pub.getNumSubscribers()<1){
    if(!ros::ok())  return 0;
    ROS_WARN_ONCE("Please create a subscriber to the maker");
    sleep(1);
  }


  // initiate markers
  marker_initiate(paths);

  //----------------Pedsim initiate---------------------
  //create output writer
  Ped::OutputWriter *ow = new Ped::FileOutputWriter();
  ow->setScenarioName("Example_self 01");

  //scene parameter process
  read_in_param(nh,scene_data,waypoint);

//  //draw the boundry
//  geometry_msgs::Point left_down;
//  left_down.x=scene_data[0];
//  left_down.y=scene_data[1]-scene_data[3];
//  left_down.z=0;
//  geometry_msgs::Point left_up;
//  left_down.x=scene_data[0];
//  left_down.y=scene_data[1];
//  left_down.z=0;
//  geometry_msgs::Point right_down;
//  left_down.x=scene_data[0]+scene_data[2];
//  left_down.y=scene_data[1]-scene_data[3];
//  left_down.z=0;
//  geometry_msgs::Point  right_up;
//  left_down.x=scene_data[0]+scene_data[2];
//  left_down.y=scene_data[1];
//  left_down.z=0;
//  scene_marker[0].points.push_back(left_down);
//  scene_marker[0].points.push_back(left_up);
//  scene_marker[1].points.push_back(right_up);
//  scene_marker[1].points.push_back(right_down);
//  scene_marker[2].points.push_back(left_down);
//  scene_marker[2].points.push_back(right_down);
//  scene_marker[3].points.push_back(left_up);
//  scene_marker[3].points.push_back(right_up);

//  for(std::vector<visualization_msgs::Marker>::iterator it=scene_marker.begin();it!=scene_marker.end();++it)
//    scene_pub.publish(*it);

//set the scene
  Ped::Tscene *pedscene = new Ped::Tscene(scene_data[0],scene_data[1],scene_data[2],scene_data[3]);
  pedscene->setOutputWriter(ow);

   Ped::Twaypoint *w1 =  new Ped::Twaypoint(waypoint[0],waypoint[1],waypoint[2]);
   Ped::Twaypoint *w2 =  new Ped::Twaypoint(waypoint[3],waypoint[4],waypoint[5]);

  int pos=0;
  for (int i=0;i<10;i++){
    Ped::Tagent *a =new Ped::Tagent();
    a->addWaypoint(w1);
    a->addWaypoint(w2);

    a->setPosition(0,pos++,0);

    pedscene->addAgent(a);
  }
  //set obstacle
  set_obstacle(scene_pub,pedscene,4,2,-20,-10);

//  //create grid map
//  grid_map::GridMap map({"elevation"});
//  map.setFrameId("map");
//  map.setGeometry(grid_map::Length(20,20),1);


//  //give the map a value
//  for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it) {
//     grid_map::Position position;
//     map.getPosition(*it, position);
//     map.at("elevation", *it) = 0;
////      map.at("elevation", *it) =2;
//   }

//  //publish the grid map
//  ros::Time time = ros::Time::now();
//  map.setTimestamp(time.toNSec());
//  grid_map_msgs::GridMap message;
//  grid_map::GridMapRosConverter::toMessage(map, message);
//  publisher.publish(message);

  while(nh.ok()){


      pedscene->moveAgents(0.5);
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
