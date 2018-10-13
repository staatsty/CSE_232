//proj09_trimap
//create a class and function methods for the class
//sec 04
//11/20/2017
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform; using std::upper_bound; using std::find; using std::binary_search;
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
#include "proj09_trimap.h"

TriMap::TriMap(const Element& e){
    
    vec_={e};                      //constructor for TriMap
}
TriMap::TriMap(initializer_list<Element> d){
    vec_=d;                        //constructor for TriMap
}




ostream& operator<<(ostream& out, const Element& e){
    out<<e.key_<<":"<<e.value_<<":"<<e.index_;
    return out;//<< operator overide to print element
}


ostream& operator<<(ostream& out, const TriMap& t){
    int i= t.vec_.size();
    if (t.vec_.size()==1){
        out<<t.vec_.at(0);
    }
    else{
    for(int z = 0; z<i; ++z){
        if(z==i-1){              //<< operator overide to print Trimap
            out<<t.vec_.at(z);
        }
        else{
        out<<t.vec_.at(z)<<", ";
    }}
    }
    return out;
}

size_t TriMap::size(){
    size_t x;
    x= vec_.size();//method that returns the size of TriMap
    return x;
}
//method that inserts values into trimap
bool TriMap::insert(string key,string value){
    int i= vec_.size();
    
    for(auto z :vec_){
        if(z.key_==key){//returns fals if key exsist already
            return false;}}
    Element e(key,value,i);       
    vec_.push_back(e);//if not creates new Element and pushes it into vec_
    std::sort(vec_.begin(),vec_.end(),[](Element lhs, Element rhs){
        return lhs.key_<rhs.key_;//sort with lambda to sort trimap by key value
    });
    return true;//returns true when new element is inserted and trimap is sorted
}
//method that inserts values into trimap
bool TriMap::remove(string key){
   size_t count =0;
   size_t index;
    for(auto z :vec_){
        count++;
        
        if(z.key_==key){//loops through trimap and remove element if key exsist
        vec_.erase(vec_.begin()+count-1);
         index= z.index_;
            break;
        }
         else{
             continue;
         }
        
         }
    if (count == vec_.size()){
            return false;//returns false if  no key exsist
        }
    int loop=0;
    int i=vec_.size();
    for(int z = 0; z<i; ++z){
            loop++;
            if (vec_.at(z).index_>index){//after removal loops and fixes indexs
            vec_.at(z).index_=vec_.at(z).index_-1;
            }
            if(i==loop){//once index is adjusted returns true
                return true;
            }
            else{
                continue;
                
            }
          }
    }
    //method that returns element pointer to key value in trimap
Element* TriMap::find_key(const string& s){
  Element e1;
  e1.key_=s;
  e1.value_="t";//creates new element to hold key
  e1.index_=5;
  int i = vec_.size(); 
     
  auto pos = lower_bound(vec_.begin(),vec_.end(),e1,[]( Element e,  Element e1){
        return e.key_<e1.key_;//uses binary search lower bound to find key
   });
   if (pos == vec_.end()){
       Element& x=vec_.at(i-1);//error check for last element in the search
       if(x.key_==s){
       return &x;} //returns element pointer
       }
   if(pos == vec_.end()){
         return nullptr;//returns null pointer if no element with the key is                                                                            //found
       }
       if (pos==vec_.end()-2){
           return nullptr;
       }
  else{
        return &(*pos);//returns element pointer if found
       }
   }
   
   
  
//method that returns element pointer to value "value" in trimap
Element* TriMap::find_value(const string& v){
    int i = vec_.size();
    int count=0;
    
    for(int z = 0; z<i; ++z){
        count ++;
        if (vec_.at(z).value_ == v){//uses linear search to find if value                                           //matches value passed 
        Element &x=vec_.at(z);
            return &x;//returns element pointer if found
        }
        else{
            continue;
        }
    }
    if(count == i){
    return nullptr;}//else returns null pointer
}
//method that returns element pointer to index value in trimap
Element* TriMap::find_index(size_t index){
    int i = vec_.size();
    int count=0;
    
    for(int z = 0; z<i; ++z){      //this is nearly identical to previous
        count ++;                  // method function
        if (vec_.at(z).index_ == index){
           Element &x=vec_.at(z);
            return &x;
        }
        else{
            continue;
        }
    }
    if(count == i){
    return nullptr;}
}








