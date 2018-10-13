//proj10_knapsack
//create a class and function methods for the class involving knapsack problem
//sec 04
//11/29/2017
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
#include "proj10_package.h"


//<<operator overload to print out package values
ostream& operator<<(ostream& out, Package& p){
    out<<p.weight_<<":"<<p.priority_;
    return out;//<< operator overide to print element
}
//creates a ratio between weight and priorty and compares that ratio to other packages. returns true if a Package has a higher ratio value then the other
bool package_compare(const Package &p1, const Package &p2){
    double p1_p, p1_w ,p2_p, p2_w;
    p1_p =p1.priority_;
    p1_w =p1.weight_;
    p2_p =p2.priority_;
    p2_w =p2.weight_;
    auto ratio_1 = p1_p/p1_w;
    auto ratio_2 = p2_p/p2_w;
    if(ratio_1>=ratio_2){
        return true;
    }
    else{
        return false;
    }
}









