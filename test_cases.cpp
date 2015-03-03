/* 
 * File:   test_cases.cpp
 * Author: akkas
 * 
 * Created on December 9, 2014, 2:29 AM
 */

#include "test_cases.h"
test_cases::test_cases() {
}

test_cases::test_cases(const test_cases& orig) {
}

test_cases::~test_cases() {
}
void test_cases::empty_string_default_constructor(){
    String string;
    ASSERT(string.size()==0);
}
void test_cases::char_to_string_constructor(){    	
    String string("test string");
    char * data=string.to_C_string();
    ASSERT(strcmp(data, "test string")==0);
    delete [] data;
}
void test_cases::char_to_string_lenght_constructor(){
    String string("test string");
    ASSERT(string.size()==11);
}
void test_cases::correct_data_copy_constructor(){
    String string("test string");
    String str_copy(string);
    char* char_string=string.to_C_string();
    char* char_str_copy=str_copy.to_C_string();
    ASSERT(strcmp(char_string,char_str_copy)==0);
    delete [] char_string;
    delete [] char_str_copy;
}
void test_cases::assignment_operator(){
    String string="test string";
    char* char_string=string.to_C_string();
    ASSERT(strcmp(char_string,"test string")==0);
    delete [] char_string;
}
void test_cases::assignment_operator_string_length(){
    String string="test string";
    ASSERT(string.size()==11);
}
void test_cases::subscript_operator_for_valid_index(){
    String string="test string";
    char ch=string[0];
    ASSERT(ch=='t');
}
void test_cases::subscript_operator_for_negative_index(){
    String string="test string";
    try{
    char ch=string[-1];
    }
    catch(const std::exception &ex){
        ASSERT(strcmp(ex.what(),"index out of range")==0);
    } 
}
void test_cases::subscript_operator_for_set_value(){
    String string="test string";
    string[0]='s';
    char* char_string=string.to_C_string();
    ASSERT(strcmp(char_string,"sest string")==0);
    delete [] char_string;
}
void test_cases::swap_strings(){
    String str_1="first string";
    String str_2="second string";
    str_1.swap(str_2);
    char* char_str_1=str_1.to_C_string();
    char* char_str_2=str_2.to_C_string();
    ASSERT((strcmp(char_str_1,"second string")==0)&& (strcmp(char_str_2,"first string")==0));
    delete [] char_str_1;
    delete [] char_str_2;
}
void test_cases::size_for_empty_string(){
    String string="";
    ASSERT(string.size()==0);
}
void test_cases::size_for_valid_string(){
    String string="test string";
    ASSERT(string.size()==11);
}
void test_cases::check_to_string_char(){
    String string="test string";
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"test string")==0);
    delete [] char_str;
}
void test_cases::check_to_string_char_for_empty_string(){
    String string="";
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"")==0);
    delete [] char_str;
}
void test_cases::push_back_to_string(){
    String string="test string";
    string.push_back('a');
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"test stringa")==0);
    delete [] char_str;
}
void test_cases::push_back_to_string_check_length(){
    String string="test string";
    string.push_back('a');
    ASSERT(string.size()==12);
}
void test_cases::push_back_to_empty_string(){
    String string="";
    string.push_back('a');
    char * char_str=string.to_C_string();
    ASSERT(string.size()==1 && strcmp(char_str,"a")==0);
    delete [] char_str;
}
void test_cases::pop_back_from_string(){
    String string="test string";
    char ch=string.pop_back();
    ASSERT(ch=='g');
}
void test_cases::pop_back_from_string_check_string(){
    String string="test string";
    char ch=string.pop_back();
    char* char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"test strin")==0);
    delete [] char_str;
}
void test_cases::pop_back_from_string_check_length(){
    String string="test string";
    char ch=string.pop_back();
    ASSERT(string.size()==10);
}
void test_cases::pop_back_from_empty_string(){
    String string="";
    try{
    char ch=string.pop_back();
    }
    catch(std::exception &ex){
        ASSERT(strcmp(ex.what(),"string is empty")==0);
    }
}
void test_cases::erase_with_valid_index(){
    String string="test string";
    string.erase(0,2);
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"t string")==0)
    delete [] char_str;
}
void test_cases::erase_with_invalid_index(){
    String string="test string";
    try{
    string.erase(0,12);
    }
    catch(std::exception &ex){
        ASSERT(strcmp(ex.what(),"index out of range")==0);
    }
}
void test_cases::insert_to_start_of_string(){
    String string="test string";
    string.insert(0,'a');
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"atest string")==0 && string.size()==12)
    delete [] char_str;
}
void test_cases::insert_to_middle_of_string(){
    String string="test string";
    string.insert(5,'a');
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"test astring")==0 && string.size()==12)
    delete [] char_str;
}
void test_cases::insert_to_end_of_string() {
    String string="test string";
    string.insert(11,'a');
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"test stringa")==0 && string.size()==12)
    delete [] char_str;
}
void test_cases::string_out_put_operator(){
    std::ostringstream out;
    String string("test string");
    char * char_str=string.to_C_string();
    out<<string;
    ASSERT(strcmp(char_str, (out.str()).c_str())==0);
    delete [] char_str;
}
void test_cases::string_input_operator(){
    String string;
    std::istringstream in("test string");
    in >> string;
    char * char_str=string.to_C_string();
    ASSERT(strcmp(char_str,"test string")==0)
    delete [] char_str;
}
void test_cases::string_input_operator_check_length(){
    String string;
    std::istringstream in("test string");
    in >> string;
    ASSERT(string.size()==11);
}
