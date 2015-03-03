/* 
 * File:   String.h
 * Author: akkas
 *
 * Created on December 2, 2014, 3:12 PM
 */

#ifndef STRING_H
#define	STRING_H
#include <cstring>
#include <iostream>
class String {
public:
    String();//default constructor
    String(const char*);//overloaded constructor
    String(const String& orig);//copy constructor
    virtual ~String();//destructor
    void string_copy(char*,const char*);//copies source string to destination
    int string_length(const char*);//returns length of string
    String& operator=(const char *);//overloaded assignment operator
    char& operator[](const int);//overloaded subscript operator
    friend std::ostream& operator<<(std::ostream&,const String&);//overloaded output operator
    friend std::istream& operator>>(std::istream&,String&);//overloaded input operator
    void swap(String&);//swap two strings
    int size();//returns size of string
    char * to_C_string();//return cstring 
    void push_back(char);//add character at end of string
    char pop_back();//removes last character of string
    void erase(int,int);//erase characters from starting to ending position
    void insert(int,char);//inserts character at specific position
    char* begin();//returns string start
    char* end();//returns string end i.e '\0'
private:
    char * data; //stores data
    int length; //length of data stored
    int capacity;// capacity of buffer

};

#endif	/* STRING_H */