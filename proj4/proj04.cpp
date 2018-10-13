//sec 004 10/2/2017 proj#4
#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
             
// meta, strictly increase
// plain, non-strictly increase
// kata, strictly decrease
// nialp, non-strictly decrease
// non, none of the above

const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";

bool metadrome(string n,int base){
    string new_base= base_vals.substr(0,base);//finds range of values first
    string empty_str="";
    for(unsigned int i=0;i<n.length();i+=2){

      int index_1=new_base.find(n[i]);   //loops through the legth of the string
      int index_2=new_base.find(n[i+1]);// and finds index values of the chars
     
     if(n[i]==n[i+1]||n[i+1]==n[i+2]){//checks for same values next to eachother
         
         break;
     }
      if(index_1<index_2){//adds charcter value to a empty string
          empty_str+=n[i];//to see if it matches input
          empty_str+=n[i+1];//as long as its increasing
          continue;}
        
        
      if(i+1==n.length()){
          empty_str+=n[i];
      }
      
      else{
          break;
          
      }}
      if(empty_str.length()!=n.length()){
          empty_str+=n[4];
           } 
      
     if (empty_str==n){//returns based on if its metadrome
     return true;}
      else{
          return false;
      }
     }

bool plaindrome(string n,int base){
 string new_base= base_vals.substr(0,base);//finds range of values first
    string empty_str="";
    for(unsigned int i=0;i<n.length();i+=2){
      //char s =n[i];
      int index_1=new_base.find(n[i]);
      int index_2=new_base.find(n[i+1]);
      if(index_1<index_2 || index_1 == index_2){// same as before except this 
          empty_str+=n[i];                    //function allows same values
          empty_str+=n[i+1];                  //next to eachother
          continue;}
      if(i+1==n.length()){
          empty_str+=n[i];
      }
      
      else{
          break;
      }
      }
     if (empty_str==n){//returns based on if its plaindrome
     return true;}
      else{
          return false;
          }   
}

bool katadrome(string n,int base){
string new_base= base_vals.substr(0,base);//finds range of values first
    string empty_str="";
    string adj_str;
    for(unsigned int i=0;i<n.length();i+=2){
      int index_1=new_base.find(n[i]);
      int index_2=new_base.find(n[i+1]);
      if(index_1>index_2){// same as before except this function
          empty_str+=n[i];//checks for decreasing rather ihan increasing
          empty_str+=n[i+1];//so logic gets "flipped" to acccomidate
          continue;}
      if(i+1==n.length()){
          empty_str+=n[i];
      }
      
      else{
          break;
      }
      }
      
    adj_str=empty_str.substr(0,empty_str.length());
     if (adj_str==n){
     return true;}//returns based on if its katadrome
      else{
          return false;
          }   
}

bool nialpdrome(string n,int base){
string new_base= base_vals.substr(0,base);
    string empty_str="";
    string adj_str;
    for(unsigned int i=0;i<n.length();i+=2){
      //char s =n[i];
      int index_1=new_base.find(n[i]);
      int index_2=new_base.find(n[i+1]);
      if(index_1>index_2|| index_1 == index_2){// same as before except this 
          empty_str+=n[i];                     //function alows same values
          empty_str+=n[i+1];
          continue;}
      if(i+1==n.length()){
          empty_str+=n[i];
      }
      
      else{
          break;
      }
      }
     if (empty_str==n){//returns based on if its nialpdrome
     return true;}
      else{
          return false;
          }   
}

string classify(string n,int base){
bool truth_1 = metadrome ( n, base);
bool truth_2 = plaindrome ( n, base);
bool truth_3 = katadrome (n,  base);
bool truth_4 = nialpdrome ( n,  base);
if(truth_2==true){
    if(truth_1==true){
        return("metadrome");//set of nested ifs to test 
    }                       //the classification of the input
    else{                   //the decsion is based on the truth values
        return("plaindrome");// of the functions above.
    }
}
if(truth_4==true){
    if(truth_3==true){
        return("katadrome");
    }
    else{
        return("nialpdrome");
    }
}
else{
    return("nondrome");
}
}
int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout<< metadrome (num, base) << " "
      << plaindrome (num, base) << " "
      << katadrome (num, base) << " "
      << nialpdrome (num, base) << " "
      << classify(num, base) << endl;
}
    



  
