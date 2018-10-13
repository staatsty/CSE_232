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
#include "proj08_twod.h"
//constructor for TwoD
TwoD::TwoD(double xval, double yval){
    x=xval;
    y=yval;
}
//method that turns a TwoD into a str
string TwoD::to_string(){
    ostringstream oss;
    oss<<fixed<<setprecision(2)<<"("<<x<<", "<<y<<")";
   return oss.str();
}
//method that takes 2 TwoD and finds difference 
TwoD TwoD::diff(TwoD(z)){
    double v1= (z.x)-x;//subs x and y values and returns new TwoD
    double v2 = (z.y)-y;
    TwoD new_val(v1,v2);
    return new_val;
}
//method that takes TwoD and double and finds product
TwoD TwoD::mult(double z){
    double x1=z*x;
    double y1=z*y;//multiplys x and y by z
    TwoD value(x1,y1);
    return value;//returns new TwoD
    
}

//method that takes 2 TwoD and finds dot product
double TwoD::dot_product(TwoD(z)){
    double v1= (z.x)*x;
    double v2 = (z.y)*y;//performs dot product algorithm
    double result = v1 + v2;
    return result;//returns new TwoD
}
//method that takes TwoD and finds magnitude
double TwoD::magnitude_squared(){
    double v1= x*x;//squares x and y and returns their sum
    double v2 = y*y;
    double result = v1 + v2;
    return result;//returns result
}










