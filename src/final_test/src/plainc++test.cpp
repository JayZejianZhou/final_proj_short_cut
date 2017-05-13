#include "iostream"
#include "fstream"
#include "cmath"
#include <navigation.h>
#include <pedsim/include/pedsim/ped_obstacle.h>
#include <pedsim/include/pedsim/ped_scene.h>
#include <pedsim/include/pedsim/ped_waypoint.h>
#include <pedsim/include/pedsim/ped_outputwriter.h>
#include <pedsim/include/pedsim/ped_obstacle.h>
//given agent number,11 maximum
#define AGENT_NUM 3

//put coordinates in
int main(){
    double boundry[36]={ 0,   40,   0,   0,
                         0,   40,  20,  40,
                         20,  40,  20,   0 ,
                         0,    0,  20,0,
                         0,30,15,30,
                         5,20,20,20,
                         0,15,5,15,
                         10,15,15,15,
                         5,10,15,10};
    std::vector<Ped::Twaypoint*> waypoints;
    std::vector<double> agent1;
    std::vector<double> agent2;
    std::vector<double> agent3;
    std::vector<double> robot;

    Navigation na(0,40,20,0,11,17,2,2);
    na.navigate(boundry,waypoints);
    //----------------Pedsim initiate---------------------
    //set the scene
    Ped::Tscene *pedscene = new Ped::Tscene(-200,-200,400,400);
    for(int i=0;i<9;i++){
        Ped::Tobstacle *boundry_o = new Ped::Tobstacle(boundry[4*i],boundry[4*i+1],boundry[4*i+2],boundry[4*i+3]);
        pedscene->addObstacle(boundry_o);
    }
    Ped::Twaypoint *w1 =  new Ped::Twaypoint(1,-7,0.5);
    Ped::Twaypoint *w2 =  new Ped::Twaypoint(6,-3,0.5);

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
//    Get another robot agent working
    Ped::Tagent *robot_o = new Ped::Tagent();
    for(std::vector<Ped::Twaypoint*>::iterator it=waypoints.begin();it<waypoints.end();it++)
      robot_o->addWaypoint(*it);
    robot_o->setPosition(1,-6,0);
    pedscene->addAgent(robot_o);

    int count=0;//run count
    while(count++<100){
        pedscene->moveAgents(0.5);
        agent1.push_back(a1->getPosition().x);
        agent1.push_back(a1->getPosition().y);

        agent2.push_back(a2->getPosition().x);
        agent2.push_back(a2->getPosition().y);

        agent3.push_back(a3->getPosition().x);
        agent3.push_back(a3->getPosition().y);

        robot.push_back(robot_o->getPosition().x);
        robot.push_back(robot_o->getPosition().y);

    }



    //clean up the mess, free the memory
    for (Ped::Tagent * agent :pedscene->getAllAgents()) delete agent;
    delete pedscene;

    return 0;
}
