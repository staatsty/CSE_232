//sec04 10-23-2017 proj#6
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
#include<fstream>
using std::ifstream;
// any other includes you need

#include "proj06_functions.h"

// your functions after this

string to_binary(int num){
    if(num<=255 and num>=0){//error check makes sure num is within range
       
    
   string binary_str ="";
    while(true){
      if (binary_str.length()==8){//breaks once string is complete
          break;
      }   
      if (int(num)%2==0){
        binary_str+="0";//adds zero if remainder is 0
        num/=2;
        continue;
    }
      else{
        binary_str+="1";
        num/=2;//adds 1 if remainder is not 0
        continue;
      }
      
     
    
}// of to_binary

string reverse_binary="";
for(int i=7;i>=0;i-=1){
    reverse_binary+=binary_str[i];//reverse string for correct output
}
return reverse_binary;
}
else{
     return "00000000";//error return value
}
}

int next_val(const vector<int> &v, const string &rule_binary_string){
    
    if (v.at(0)==1 and v.at(1)==1 and v.at(2)==1){
        char x = rule_binary_string[0];
        if (x=='0'){
        return 0;//bunch of ifs for each truth value acording to the rule num
        }
        else{
        return 1;}
    }
    if (v.at(0)==1 and v.at(1)==1 and v.at(2)==0){
       char x = rule_binary_string[1];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    if (v.at(0)==1 and v.at(1)==0 and v.at(2)==1){
        char x = rule_binary_string[2];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    if (v.at(0)==1 and v.at(1)==0 and v.at(2)==0){
        char x = rule_binary_string[3];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    if (v.at(0)==0 and v.at(1)==1 and v.at(2)==1){
        char x = rule_binary_string[4];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    if (v.at(0)==0 and v.at(1)==1 and v.at(2)==0){
        char x = rule_binary_string[5];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    if (v.at(0)==0 and v.at(1)==0 and v.at(2)==1){
        char x = rule_binary_string[6];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    if (v.at(0)==0 and v.at(1)==0 and v.at(2)==0){
        char x = rule_binary_string[7];
        if (x=='0'){
        return 0;
        }
        else{
        return 1;}
    }
    else{

    return 0;}
}//end of next_val

vector<int> one_iteration(const vector<int> &v, const string &rule_binary_string){
    vector<int> v_1=v;
    v_1.insert(v_1.begin(),0);//adds zeros at beging and end of vector as place 
    v_1.push_back(0);         // holder
    vector<int> empty_vec;
    for(int i=0;i<9;i+=1){
       
        int index_0,index_1,index_2;
        if (i>=7){
        index_0=6;
        index_1=7;//variables to hold proper indexing values based on i
        index_2=8;
        
        }
        else{
        index_0=0+i;
        index_1=1+i;
        index_2=2+i;
        }                    //new vector to find next value
        vector<int> new_vec={v_1.at(index_0),v_1.at(index_1),v_1.at(index_2)};
        int value= next_val(new_vec,rule_binary_string);
        empty_vec.push_back(value);//adds value to new vector
        
        //continue;
    }
    empty_vec.pop_back();
    empty_vec.pop_back();//removes extra zeros from vector
    return empty_vec;
}// of one_iteration

string vector_to_string(const vector<int> &v){
    string empty_string;
     for(unsigned int i=0;i<v.size();i+=1){
         int a = v.at(i);//creates a string from the values in the vector
         std::ostringstream oss;
         oss<<a;
         empty_string+= oss.str()+",";
            
    }
     empty_string.pop_back();//removes trailing comma
     return empty_string;
}// of vector_to_string
   
void read_vector(vector<int> &v, string fstring){
    ifstream myfile;
    myfile.open(fstring);//opens file
    for(string line;getline(myfile,line);){//loops trough file
        for(unsigned int i=0;i<=line.length();i+=1){
       if(isalnum(line[i])){//if value is alnum add to vector
           int value= line[i];
            v.push_back(value);
       }
       else{
           continue;
       }
       
        }
     
    }
    
}//of read_vector
   
       
   








// a freebie!
// takes in a vector of 0,1
// outputs a string of '_' or '*'
//string pretty_print(vector<int> & v){
 // ostringstream oss;
  //transform(v.begin(), v.end(), ostream_iterator<char>(oss),
	   // [] (int i) {
	  //    return (i==0) ? '_' : '*';
	  //  }
	  //  );
  //  return oss.str();
//}
