/* 
 * File:   test_cases.h
 * Author: akkas
 *
 * Created on December 9, 2014, 2:29 AM
 */

#ifndef TEST_CASES_H
#define	TEST_CASES_H
#include <exception>
#include <iostream>
#include <sstream>
#include "test_driver.h"
#include "String.h"
class test_cases {
public:
    test_cases();
    test_cases(const test_cases& orig);
    virtual ~test_cases();
    void empty_string_default_constructor();
    void char_to_string_constructor();
    void char_to_string_lenght_constructor();
    void correct_data_copy_constructor();
    void assignment_operator();
    void assignment_operator_string_length();
    void subscript_operator_for_valid_index();
    void subscript_operator_for_negative_index();
    void subscript_operator_for_set_value();
    void swap_strings();
    void size_for_empty_string();
    void size_for_valid_string();
    void check_to_string_char();
    void check_to_string_char_for_empty_string();
    void push_back_to_string();
    void push_back_to_string_check_length();
    void push_back_to_empty_string();
    void pop_back_from_string();
    void pop_back_from_string_check_string();
    void pop_back_from_string_check_length();
    void pop_back_from_empty_string();
    void erase_with_valid_index();
    void erase_with_invalid_index();
    void insert_to_start_of_string();
    void insert_to_middle_of_string();
    void insert_to_end_of_string();
    void string_out_put_operator();
    void string_input_operator();
    void string_input_operator_check_length();
private:

};

#endif	/* TEST_CASES_H */

