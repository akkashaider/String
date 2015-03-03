/* 
 * File:   String.cpp
 * Author: akkas
 * 
 * Created on December 2, 2014, 3:12 PM
 */

#include "String.h"
#include <stdexcept> 
//default constructor
String::String():length(0),capacity(0) {
   
    this->data=new char[1];
    data[0]='\0';
}

//destructor
String::~String() {
    delete []this->data;
    this->length=0;
    this->capacity=0;
}

//overloaded constructor 
//convert char* to String
String::String(const char* value){

    this->length=string_length(value);
    this->data=new char[this->length+1];
    this->capacity=this->length;
    string_copy(this->data,value);
}

//Copy Constructor
String::String(const String& orig) {
   
    this->length=orig.length;
    this->capacity=this->length;
    this->data=new char[orig.length+1];
    string_copy(this->data,orig.data);
}

//returns size of string
int String::size(){
    return this->length;
}
//copies src string to dst
void String::string_copy(char* dst,const char* src){
    int indexer=0;
    while(src[indexer]!='\0'){
        dst[indexer]=src[indexer];
        indexer++;
    }
    dst[indexer]='\0';
}
//returns length of string
int String::string_length(const char* str){
    int len=0;
    while(str[len]!='\0')
        len++;
    return len;
}

//overloaded assignment operator 
String& String::operator =(const char* value){
    
   this->length=string_length(value);
   delete [] this->data;
   this->data=new char[this->length+1];
   string_copy(this->data,value);
   return *this;
}

//overloaded subscript operator
char& String::operator [](const int index){
    
    if(index <0 || index>= this->length)
        throw std::out_of_range("index out of range");
    return this->data[index];
}

//overloaded output operator
std::ostream& operator <<(std::ostream& out, const String& string){
        out<<string.data;
        return out;
}

//overloaded input operator
std::istream& operator >>(std::istream& in, String& string){
    delete [] string.data;
    
    string.data=new char[1024];
    string.capacity=1024;
    in.getline(string.data,1024);
    string.length=strlen(string.data);
    return in;
}

//Swaps two Strings
void String::swap(String & second){
    int size1=this->length;
    int size2=second.length;
    
    char * temp=new char[size1+1];
    string_copy(temp,this->data);
    
    delete []this->data;
    this->data=new char[size2+1];
    this->length=size2;
    string_copy(this->data,second.data);
    
    delete [] second.data;
    second.data=new char[size1+1];
    string_copy(second.data,temp);
    second.length=size1;
    
    delete [] temp;
}

// convert String to cstring
char* String::to_C_string(){
    char * arr=new char[this->length+1];
    string_copy(arr,this->data);
    return arr;
}

// add character to end of string
void String::push_back(char ch){
    if(this->capacity>(this->length+1)){
        this->data[this->length]=ch;
        this->data[this->length+1]='\0';
        this->length+=1;
    }
    else{
        char* temp=new char[this->length+1];
        string_copy(temp,this->data);
        delete [] this->data;
        
        if(this->capacity>0){
        this->data=new char[this->capacity*2];
        this->capacity*=2;
        }
        else{
        this->data=new char[8];
        this->capacity=8;    
        }
        for(int i=0;i<this->length;i++)
            this->data[i]=temp[i];
        this->data[this->length]=ch;
        this->data[this->length+1]='\0';
        this->length+=1;
        delete []temp;
    }
}

//removes and returns last character of string
char String::pop_back(){
    if(size()==0)
        throw std::out_of_range("string is empty");
    char ret=this->data[this->length-1];
    this->length-=1;
    this->data[this->length]='\0';
    return ret;
}

//erase characters from start to end
void String::erase(int start, int end){
    
    if(start< 0 || end > this->length ||start>end)
        throw std::out_of_range("index out of range");
    int count=0;
    int indexer=end+1;
    while(this->data[indexer]!='\0'){
        this->data[start+count]=this->data[indexer];
        count++;
        indexer++;
    }
    this->data[start+count]='\0';
    this->length-=(end+1-start);
}

//insert character at specific index
void String::insert(int index, char ch){
  if(index<0 || index>this->length)
      throw "Index out of bound";
  char* temp = new char[this->length+2];
  
  for (int i=0; i<=this->length; i++){
      if (i < index){
       temp[i] = this->data[i];
      }
      if (i == index){
      temp[i] = ch;
      }
       
      if (i > index){
      temp[i] = data[i-1];
      }
  }
  temp[this->length+1]='\0';
    
  delete [] this->data;
  this->data=new char[this->length+2];
  
  strcpy(this->data,temp);
  this->length+=1;
  this->capacity=this->length;
  delete [] temp; 
}

//return string starting character
char* String::begin(){
    return &data[0];
}

//return end of string i.e '\0'
char* String::end(){
    return &data[this->length];
}

