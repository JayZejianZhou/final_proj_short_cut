#include "navigation.h"
#include <D_star_lib.h>
#include <pedsim/ped_waypoint.h>

Navigation::Navigation(int left_t, int top_t, int right_t, int down_t, int start_x, int start_y, int goal_x, int goal_y)
{
  left=left_t;
  right=right_t;
  top=top_t;
  down=down_t;
  m.map_length=right-left;
  m.map_width=top-down;
  offset_x=0-left;
  offset_y=0-down;//use offset to move the operate scene to 0,0
  m.goal_x=goal_y+offset_y;
  m.goal_y=goal_x+offset_x;
  m.start_x=start_y+offset_y;
  m.start_y=start_x+offset_x;
  m.start_y=start_x+offset_x;
  m.start_x=start_y+offset_y;
  for(int i=0;i<m.map_width;i++)
      for(int j=0;j<m.map_length;j++){
          m.nodes[i][j].set_x(i);//initiate nodes array
          m.nodes[i][j].set_y(j);
      }
  m.nodes[7][13].set_k(9999);
}
//find the turning points
void Navigation::find_tp()
{
  Node *temp=&m.nodes[m.start_x][m.start_y];
  topoligy_list.push_back(temp);//put the start point in the waypoint list
  while(temp->get_previous()->get_previous()!=nullptr){
    if((temp->get_x()-temp->get_previous()->get_x() !=
        temp->get_previous()->get_x()-temp->get_previous()->get_previous()->get_x())
       || (temp->get_y()-temp->get_previous()->get_y() !=
           temp->get_previous()->get_y()-temp->get_previous()->get_previous()->get_y()))//turning point
      topoligy_list.push_back(temp->get_previous());//put the turning point in
    temp=temp->get_previous();
  }
  topoligy_list.push_back(temp->get_previous());//put the goal point in
}

void Navigation::navigate(double boundry[], std::vector<Ped::Twaypoint*> &waypoints)
{
  //set obstacles
  for(int i=0;i<9;i++){
    m.set_obstacle(boundry[4*i]+offset_x,boundry[4*i+1]+offset_y,boundry[4*i+2]+offset_x,boundry[4*i+3]+offset_y);
  }
  m.find_path();
  find_tp();
  for(int i=0;i<topoligy_list.size();i++){
    Ped::Twaypoint * temp=new Ped::Twaypoint(topoligy_list[i]->get_y()-offset_x,topoligy_list[i]->get_x()-offset_y,0.7);
    waypoints.push_back(temp);//push back waypoints
  }
}
