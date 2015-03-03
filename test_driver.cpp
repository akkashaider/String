/* 
 * File:   test_driver.h
 * Author: akkas
 *
 * Created on December 9, 2014, 2:35 AM
 */

#include "test_driver.h"
#include "test_cases.h"
#include <iostream>


test_driver::test_driver(void) : total_passed_tests(0), total_failed_tests(0){
add_test();
}


test_driver::~test_driver(void){
    
}

void test_driver::add_test(){
    test_cases tests;
    test_list.push_back([&]() { return tests.empty_string_default_constructor();});
    test_list.push_back([&]() { return tests.char_to_string_constructor(); });
    test_list.push_back([&]() { return tests.char_to_string_lenght_constructor();});
    test_list.push_back([&]() { return tests.correct_data_copy_constructor();});
    test_list.push_back([&]() { return tests.assignment_operator();});
    test_list.push_back([&]() { return tests.assignment_operator_string_length();});
    test_list.push_back([&]() { return tests.subscript_operator_for_valid_index();});
    test_list.push_back([&]() { return tests.subscript_operator_for_negative_index();});
    test_list.push_back([&]() { return tests.subscript_operator_for_set_value();});
    test_list.push_back([&]() { return tests.swap_strings();});
    test_list.push_back([&]() { return tests.size_for_empty_string();});
    test_list.push_back([&]() { return tests.size_for_valid_string();});
    test_list.push_back([&]() { return tests.check_to_string_char();});
    test_list.push_back([&]() { return tests.check_to_string_char_for_empty_string();});
    test_list.push_back([&]() { return tests.push_back_to_string();});
    test_list.push_back([&]() { return tests.push_back_to_string_check_length();});
    test_list.push_back([&]() { return tests.push_back_to_empty_string();});
    test_list.push_back([&]() { return tests.pop_back_from_string();});
    test_list.push_back([&]() { return tests.pop_back_from_string_check_string();});
    test_list.push_back([&]() { return tests.pop_back_from_string_check_length();});
    test_list.push_back([&]() { return tests.pop_back_from_empty_string();});
    test_list.push_back([&]() { return tests.erase_with_valid_index();});
    test_list.push_back([&]() { return tests.erase_with_invalid_index();});
    test_list.push_back([&]() { return tests.insert_to_start_of_string();});
    test_list.push_back([&]() { return tests.insert_to_middle_of_string();});
    test_list.push_back([&]() { return tests.insert_to_end_of_string();});
    test_list.push_back([&]() { return tests.string_out_put_operator();});
    test_list.push_back([&]() { return tests.string_input_operator();});
    test_list.push_back([&]() { return tests.string_input_operator_check_length();});
    
}

void test_driver::start_testing(){
    for(auto it = test_list.begin(); it != test_list.end(); it++){
        try{
            (*it)();
            total_passed_tests++;
        }
        catch(...){
            total_failed_tests++;
        }
    }
    std::cout<<"Passed tests\t"<<total_passed_tests<<std::endl;
    std::cout<<"Failed tests\t"<<total_failed_tests<<std::endl;
    }

