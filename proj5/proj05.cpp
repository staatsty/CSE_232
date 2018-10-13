// beaufort cipher, http://practicalcryptography.com/ciphers/classical-era/beaufort/

#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
string rotate_left(int rotate,string plain_text){
    if (rotate <1){
        return plain_text;
    }
    else{
   string left_string= plain_text.substr(rotate)+plain_text.substr(0,rotate);
   return left_string;}//finds and returns left rotated string
}// of rotate_left
char beaufort_letter(char plaintext_letter, char key_letter){
    if (isdigit(plaintext_letter)||isupper(plaintext_letter)||isdigit(key_letter)||isupper(key_letter)){
        return plaintext_letter;//error check for anly alpha charcters
        
    }
    else{
    char x= 'a';
    int index_value = plaintext_letter - x;         //find index of new char by 
    string new_alphabet=rotate_left(index_value,alphabet);//subtracting plain by
    int new_index=new_alphabet.find(key_letter);          //a
    return alphabet[new_index];//returns correct beaufort letter
    }
}//of beaufort_letter

char vigenere_letter(char plaintext_letter, char key_letter){
    if (isdigit(plaintext_letter)||isupper(plaintext_letter)||isdigit(key_letter)||isupper(key_letter)){//error check for anly alpha charcters
        return plaintext_letter;
    }
    else{
    char x= 'a';
    int index_value = plaintext_letter - x;
    string new_alphabet=rotate_left(index_value,alphabet);
    int new_index=alphabet.find(key_letter);
    return new_alphabet[new_index];//returns correct vigenere letter
    }
}//of vigenere_letter

string encode_beaufort(string plaintext,string key){
    string new_key=key;
    string new_plaintext="";//intialize incase key or plaintext needs changing
    for(unsigned int i=0;i<plaintext.length();i+=1){
    if (isalpha(plaintext[i])){
        new_plaintext+=plaintext[i];//errorcheck for only alpha char
    }
    else{
        continue;
    }}
    
    if(new_plaintext.length()!=key.length()){
        int num_1=new_plaintext.length()-key.length();
        for(int i=0;i<num_1;i+=1){
            new_key+=key[i];//error check for key to short
            continue;
        }
        
    }
    string adjusted_key=new_key.substr(0,new_plaintext.size());
    string empty_str="";//string to hold beaufort cipher
    for(unsigned int i=0;i<new_plaintext.length();i+=1){
         char x=beaufort_letter(new_plaintext[i],adjusted_key[i]);
        empty_str += x;//ads char to empty string
        continue;
    }
    return empty_str;
    }// of encode_beaufort
    
string encode_vigenere(string plaintext,string key){
    string new_key=key;
    string new_plaintext="";//intialize incase key or plaintext needs changing
    for(unsigned int i=0;i<plaintext.length();i+=1){
    if (isalpha(plaintext[i])){//errorcheck for only alpha char
        new_plaintext+=plaintext[i];
    }
    else{
        continue;
    }}
    if(new_plaintext.length()!=key.length()){
        int num_1=new_plaintext.length()-key.length();
        for(int i=0;i<num_1;i+=1){
            new_key+=key[i];
            continue;
        }
    }
    string empty_str="";//string to hold beaufort cipher
    for(unsigned int i=0;i<new_plaintext.length();i+=1){
         char x=vigenere_letter(new_plaintext[i],new_key[i]);
        empty_str += x;
        continue;
    }
    return empty_str;
    }// of encode_beaufort
    


int main (){
  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
    
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main
