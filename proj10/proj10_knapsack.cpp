//proj10_knapsack
//create a class and function methods for the class involving knapsack problem
//sec 04
//11/29/2017
#include<string>
using std::string; using std::getline;
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
#include "proj10_knapsack.h"
#include "proj10_package.h"
//constructor for knapsack with max weight as param
Knapsack::Knapsack(size_t max){
    capacity_=10;
    size_=0;
    weight_limit_=max;
   data_ = new Package [capacity_];
    
}
//constructor for knapsack with wlimit and capacity as param
Knapsack::Knapsack(size_t wlimit, size_t cap){
    capacity_=cap;
    size_=0;
    weight_limit_=wlimit;
    
    data_= new Package [capacity_];
}
//dtor for knapsack deletes array of packages
Knapsack::~Knapsack(){
    
    delete [] data_;
}
//copy constructor copys an exsisting knapsack
Knapsack::Knapsack(const Knapsack& k){
    capacity_=k.capacity_;
    size_=k.size_;
    weight_limit_=k.weight_limit_;
    data_= new Package[k.capacity_];
  std::copy (k.data_, k.data_+k.capacity_, data_);
}
//= overide creates apropriate assignment 
Knapsack& Knapsack::operator=(const Knapsack k ){
if (this != &k){
   delete [] data_; //deletes old array
   capacity_ = k.capacity_;
   size_ = k.size_;
   weight_limit_ = k.weight_limit_;
   data_= new Package[capacity_];//creats new array and copys in contents
   std::copy (k.data_, k.data_+k.capacity_, data_);}

    return *this;
}

//method that returns capacity of Knapsack
long Knapsack::capacity() const{
    return capacity_;
}
//method that returns size of Knapsack
long Knapsack::size() const{
    return size_;
}
//method that returns weight limit of Knapsack
long Knapsack::weight_limit() const{
    return weight_limit_;
}
//method that returns true if knapsack is empty
bool Knapsack::empty() const{
    if (size_==0){
        return true;
    }
    else{
        return false;
    }
}
//method that returns total weight of knapsack
long Knapsack::weight() const{
    long sum=0;
    for(  int i = 0; i < size_;i ++ ){//loops and adds weight_ from each Package
        sum+=data_[i].weight_;
    }
    if(sum>0){
        return sum;//returns sum if their is one
    }
    else{
        return 0;
    }
}
//method that returns total priority of knapsack
long Knapsack::priority() const{
    long sum=0;
     for(  int i = 0; i < size_;i ++ ){//identical to weight() except it takes
        sum+=data_[i].priority_;    //priority_
    }
    if(sum>0){
        return sum;
    }
    else{
        return 0;
    }
}
//method that adds Packageto knapsack if it fits
bool Knapsack::add(const Package& p){
    
    long sum = 0;
    
    for(  int i = 0; i < size_;i ++ ){//this loop sums the weight of the 
        if(data_[i].weight_==0 and data_[i].priority_==0){ //knapsack
        break;
    }
    else{            
      sum+=data_[i].weight_;  
    }
    }
    auto sack_weight = p.weight_+sum;
    if (sum == 0){//if knapsackis empty add in the Packageand return true
        data_[0]=p;
        size_++;
        return true;
    }
    if(weight_limit_>=sack_weight){//if there is room for the package in 
        int s = size_;             //knapsack
        int c = capacity_;
        if(s==c){//checks to see if more memory needs to be allocated
            auto new_data = new Package [capacity_*2]{};//doubles the amount of
            std::copy(data_,data_+capacity_,new_data);  // capacity in new array
            std::swap(new_data,data_);//use copy to old array into new one
            delete  [] new_data;// then swaps the old for new and deletes old 
            data_[size_]=p;//adda new package in at the end
            size_++;
            long capacity=capacity_*2;//updates knew capacity
            capacity_=capacity;
            return true;//returns true once everything is completed
           }
        
        else{
        for(  int i = 0; i <= size_; i = i + 1 ){//if no more memory is needed
            if (data_[i].weight_ == 0 and data_[i].priority_ == 0){//Package is 
                data_[i]=p;                        //added in loop
                size_++;
                break;
            }
            else{
                continue;
            }
            }
        return true;
        }
    }
    else{
        return false;
    }
   
    
}


//<< operator overload to print Knapsack
 ostream& operator<<(ostream& out, Knapsack& k){
    int i= k.size_;
    if (k.size_==1){
        out<<k.data_[0];
    }
    else{
    for(int z = 0; z<i; ++z){
        if(z==i-1){              //i used code similar to project 9 trimap
            out<<k.data_[z];     //<<operator overload function
        }
        else{
        out<<k.data_[z]<<", ";
    }}
    }
    return out;
}
//solve_ks function sorts knapsack with semi effiecnt filling from selection
void solve_KS(string s, Knapsack& k){

ifstream myfile(s.c_str());//opens file from string var
string line;
 int n,m,i=0;   
vector<int> c1,c2;//vector to hold values in file
int count = 0;
 if(myfile.is_open()){
	while (myfile>>n>>m) {
	    c1.push_back(n);//loops through file and appends weight and priority
        c2.push_back(m);//to end of the vectors 
        i++;
	}
	myfile.close();//closes file
	vector<Package> p_vec;//make a vector of just packages
	for(unsigned int i = 0 ; i<c2.size();i++){
	    Package p(c1.at(i),c2.at(i));//adds the packages to the vector
	    p_vec.push_back(p);
	}
	std::sort(p_vec.begin(),p_vec.end(),package_compare);//sorts the vector 
	while(true){//making use of the package_compare function
	  bool x= k.add(p_vec.at(count));//adds packages into knapsack untill
	   count++;                      //add function returns false
	   if (x == true){
	       continue;
	   }
	   else{
	       break;
	   }
	}
}
  else{
      throw std::runtime_error("Could not open file");
        //throws runtime error if file does not open
    }
    
  }

 





