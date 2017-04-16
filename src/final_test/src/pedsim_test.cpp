#include <ros/ros.h>
//#include <libpedsim/ped_includes.h>
//#include <libpedsim/ped_outputwriter.h>
//#include <libpedsim/ped_scene.h>
#include <pedsim/ped_scene.h>
#include <pedsim/ped_waypoint.h>
#include <pedsim/ped_outputwriter.h>
#include <pedsim/ped_obstacle.h>
#include <ros/time.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pedsim");
  ros::NodeHandle nh;

  //-----------------this is a simple test---------------------
  //create output writer
  Ped::OutputWriter *ow = new Ped::FileOutputWriter();
  ow->setScenarioName("Example_self 01");

  Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);
  pedscene->setOutputWriter(ow);

   Ped::Twaypoint *w1 =  new Ped::Twaypoint(-100,0,24);
   Ped::Twaypoint *w2 =  new Ped::Twaypoint(+100,0,12);

  Ped::Tobstacle *o = new Ped::Tobstacle(0,-50,0,+50);
  pedscene->addObstacle(o);
int pos=0;
  for (int i=0;i<10;i++){
    Ped::Tagent *a =new Ped::Tagent();
    a->addWaypoint(w1);
    a->addWaypoint(w2);

    a->setPosition(pos+=10,pos,0);

    pedscene->addAgent(a);
  }

    for (int i=0; i<20; ++i){
      pedscene->moveAgents(0.3);
      ros::Duration(0.3).sleep();
    }
    for (Ped::Tagent * agent :pedscene->getAllAgents()) delete agent;
    delete pedscene;
    delete w1;
    delete w2;
    delete o;
    delete ow;


  ROS_INFO("Hello world!");
}
