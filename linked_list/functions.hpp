#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "data.hpp"
#include <string>

void main_menu();
void reg();
bool login();
void add_new_tutor();
void display();
void search();
void modify();
void sort();
void report();
void remove();
Staff* add_new_staff_node(int, std::string, int, std::string, std::string);

#endif