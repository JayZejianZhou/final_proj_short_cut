#include <ros/ros.h>
#include <ros/time.h>
#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/GetGridMap.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pedsim_demo");
  ros::NodeHandle nh("~");
  ros::Publisher publisher = nh.advertise<grid_map_msgs::GridMap>("grid_map", 1, true);
  ros::Rate r(30);
  //create grid map
  grid_map::GridMap map({"elevation"});
  map.setFrameId("map");
  map.setGeometry(grid_map::Length(6.0,6.0),0.03);

  while(nh.ok()){
    ros::Time time = ros::Time::now();

    for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it) {
       grid_map::Position position;
       map.getPosition(*it, position);
       map.at("elevation", *it) = -0.04 + 0.2 * std::sin(3.0 * time.toSec() + 5.0 * position.y()) * position.x();
 //      map.at("elevation", *it) =2;
     }

     //publish the grid map
      map.setTimestamp(time.toNSec());
      grid_map_msgs::GridMap message;
      grid_map::GridMapRosConverter::toMessage(map, message);
      publisher.publish(message);
      r.sleep();

  }

  ROS_INFO("Hello world!");
}
