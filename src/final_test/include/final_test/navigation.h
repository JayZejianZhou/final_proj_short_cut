#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <D_star_lib.h>
#include <vector>
#include <pedsim/ped_waypoint.h>

class Navigation
{
public:
  Map m;
  int left;
  int right;
  int top;
  int down;
  int offset_x;
  int offset_y;//put x, y offset in because some motherfuckers like using negative numbers in coodinates
public:
  std::vector<Node*> topoligy_list;//list of turning points in their path
public:
  //Navigation(){}
  Navigation(int left, int top,int right,int down, int start_x, int start_y, int goal_x, int goal_y);//TODO: resolution
  void find_tp();//find turning points
  void navigate(double boundry[36], std::vector<Ped::Twaypoint *> &waypoints);//main process function
};

#endif // NAVIGATION_H
