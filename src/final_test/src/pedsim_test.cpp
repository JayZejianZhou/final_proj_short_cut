#include <ros/ros.h>
//#include <libpedsim/ped_includes.h>
//#include <libpedsim/ped_outputwriter.h>
//#include <libpedsim/ped_scene.h>
#include <pedsim/ped_scene.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pedsim");
  ros::NodeHandle nh;

  //-----------------this is a simple test---------------------
  //create output writer
//  Ped::OutputWriter *ow = new Ped::FileOutputWriter();
//  ow->setScenarioName("Example_self 01");

  Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);

  ROS_INFO("Hello world!");
}
