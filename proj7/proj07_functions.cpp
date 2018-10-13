//proj07_knn
//find k neareast neighbors algorithm
//sec 04
//10/30/2017


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

//this function splits a string into a vector
//used the function in the split video to create this one
vector<string> split(const string &s, char delim){
    string::size_type start = 0;
    vector<string> vec_str;//some variables
    auto pos = s.find(delim,start);
    while(pos != string::npos){// loops through and extracts string based on 
        vec_str.push_back(s.substr(start,pos-start));//the split char
        start= pos+1;                             //puts the string into a vec
        pos=s.find(delim,start);
    }
    if (start!= s.size()){
    vec_str.push_back(s.substr(start));}
    
return vec_str;//returns vec
    
}//of split
//reads text file and places data into a map
void read_data(map<vector<double>, string>&m, unsigned int feature_count, ifstream &inf){
    string sline;
    while(!inf.eof()){
    getline(inf,sline);
    vector<string>v=split(sline,',');//splits the values at ,
   
    if(v.size()==0){
        break;
    }
    string key=v.at(feature_count);// value of map which is the string of flower
    v.pop_back();//removes value from vector
  
    
   
   vector<double> v2={};
   
    for(unsigned int i=0;i<feature_count;i++){
        double value = std::stod(v.at(i));//changes the nums from strings to 
        v2.push_back(value);              //doubles
    }
    
   m.insert(pair<vector<double>,string  > ( v2,key));//inserts the vector and                                                       //string into the map
    
    
    }


}//of read_data

//this function takes a pair and retuns it as a string
string pair_to_string(const pair<vector<double>, string> &p){
    ostringstream oss;
    vector<double> v= p.first;//creates vector from first value
    string key = p.second;//creates string from second value
    for(unsigned int i = 0; i< v.size(); ++i){
        oss<<fixed<<setprecision(3)<<v.at(i)<<" ";//loops through and adds                                                        //vector values to oss
    }
    oss<<key;//adds string value to oss
    return oss.str();
}//of pair_to_string

//takes a map and ostream and creates a string of map values
void print_map(const map<vector<double>, string> &m, ostream &out){
    
    for(auto iter = m.begin(); iter != m.end(); ++iter){
       out<<pair_to_string(*iter)<<endl;//loops through map and uses pair_to_str                                         //ing to create map string
       
    }
    
}// of print_map

//calculates distance from euclideam formula
double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count){
    double sum=0;
    for(unsigned int i=0;i<feature_count;i++){
         double under_root=(v2.at(i)-v1.at(i));//loops and takes vector value
        sum+=pow(under_root,2);                //does math to find right value
    }
    double sum_squared=sqrt(sum);
    return sum_squared;//reurns that value
}//of distance

//big function that finds k_neighbors by using distance function
//a new map is returned with the closest neighbors
map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k){
    map<double, vector<double>> new_m;//intialize 2 maps to stroe values
    map<vector<double>, string> new_m2;
     for(auto iter = m.begin(); iter != m.end(); ++iter){
      vector<double> v2=(iter->first);//loops through map and takes vector
      if (v2 == test){//error check if alue is in map it excludes
          continue;
      }
      else{
          
          double distance_val=distance(test,v2,test.size());//inserts the dist
           new_m.insert(pair<double,vector<double> > ( distance_val,v2));//as a                                                             //key in the map
          
      }
     }
     for(auto iter = new_m.begin(); iter != new_m.end(); ++iter){
         int z = new_m2.size();
         if(z==k){
             break;//breakes once map size is correct
         }
         else{
             vector<double> y = iter->second;
             for(auto iter = m.begin(); iter != m.end(); ++iter){
             if(iter->first==y){  //finds the new map by sorting old map by dist
             string key = iter -> second;
             new_m2.insert(pair<vector<double>,string  > ( y,key));//inserts vec
             break;                                                //inserts                                                            //string into new map
             }
             }
         }
     }
     return new_m2;
}//of k_neighbors

//uses k_neighbors to find how often the test value is in the map
double test_one(const map<vector<double>, string> &m, pair<vector<double>, string> test, int k){
    vector<double> v= test.first;
    string key = test.second;//some variables
    double num = 0;
    map<vector<double>, string> new_m=k_neighbors(m,v,k);
    for(auto iter = new_m.begin(); iter != new_m.end(); ++iter){
        if(iter->second==key){
            num+=1;//counts num of times key appears
            continue;
        }
        else{
            continue;
        }
    }
    double return_value=num/k;//return value is the count/k
    return return_value;
}//of test_one






