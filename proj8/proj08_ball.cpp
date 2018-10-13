//proj08_bouncing_balls
//find physical state of bouncing balls
//sec 04
//11/6/2017
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
#include<list>
using std::list;
#include<iostream>
using std::cout; using std::endl; using std::ostream; using std::fixed; 
#include<fstream>
using std::ifstream;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<iomanip>
using std::setprecision;
#include<cmath>
#include "proj08_ball.h"
#include "proj08_twod.h"


//constructor for Ball struct
Ball::Ball(double m, TwoD pos, TwoD speed, double r){
  mass = m;
  coords = pos;
  velocity = speed;
  radius = r;
}
  
 //method that takes a Ball and returns values in a str
 string Ball::to_string(){
    ostringstream oss;
    oss<<fixed<<setprecision(2)<<mass<<", ("<<coords.x<<", "<<coords.y<<"), "<<"("<<velocity.x<<", "<<velocity.y<<"), "<<radius;
   return oss.str();
 }
 //method that checks if a Ball is in contact with a Ball
 bool Ball::contact_ball(Ball( new_ball)){
     double radius_sum = new_ball.radius +radius;
     auto contact_dist = coords.diff(new_ball.coords);//some math based
     if(contact_dist.x<0){                            //on given formula
         contact_dist.x=contact_dist.x*-1;
     }
     if(contact_dist.x<= radius_sum){
         return true;//returns true if contact is made
     }
     else{
         return false;// returns false if no contact is made
     }
     
 }
 
 //this method checks if a ball is in contact with a wall
 bool Ball::contact_wall(long xdim, long ydim){
     auto x_value=coords.x + radius;
     auto x_value2= coords.x - radius;
     auto y_value=coords.y + radius;   //variables to hold values
     auto y_value2= coords.y - radius;
     
     if (x_value>xdim or x_value2<0){ //condtions that determine contact
         return true;//true if contact is made
     }
     if (y_value>ydim or y_value2<0){
         return true;
     }
     else{
         return false;//false if no contact
     }
     
 }
  
  //method that changes the velocity if the ball comes in contact with a wall
  TwoD Ball::update_velocity_wall(long xdim, long ydim){
      auto x_value=coords.x + radius;
      auto x_value2= coords.x - radius;
      auto y_value=coords.y + radius;
      auto y_value2= coords.y - radius;   //variables to hold values
      auto contact=contact_wall(xdim,ydim);
      TwoD new_v;
      if (contact == true){
      if (xdim==0 and ydim==0){//checks for contact first
          return velocity;
      }
     if (x_value>xdim or x_value2<0){
         new_v.x=(velocity.x)*-1;//updates x value if hiting wall on x-axis
     }
     else{
        new_v.x=(velocity.x); 
     }
      
      
     if (y_value>ydim or y_value2<0){
          new_v.y=(velocity.y)*-1;//updates y value if hiting wall on y-axis
         
      }
      else{
        new_v.y=(velocity.y); 
     }
      return new_v;//returns updated velocity
          
      }
      else{
          return velocity;//if no contact returns origanal velocity
      }
  }
  //changes velocity if two balls are in contact
  TwoD Ball::update_velocity_ball(Ball(b)){
      auto contact=contact_ball(b);
      if (contact == true){//checks if ball is in contact with a ball
      TwoD x_diff=coords.diff(b.coords);
      TwoD v_diff = velocity.diff(b.velocity);
      double dot_val = v_diff.dot_product(x_diff);//variables hold values to 
      double x_diff_mag = x_diff.magnitude_squared();//do given algorithm in 
      double mass_value= (2*b.mass)/(mass+b.mass);   // proj pdf
      double multi_value=mass_value*(dot_val/x_diff_mag);
      TwoD multi_vector = x_diff.mult(multi_value);
      TwoD final_value = velocity.diff(multi_vector);
      if (isnan(final_value.x)== true or isnan(final_value.y)==true){
          return velocity;//returns orignal if nan is value
      }
      else{
          return final_value;//returns final velocity after given operations
          }
      }
      else{
          
          return velocity;
      }
  }
  
  
  
  
 