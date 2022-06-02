#include <iostream>
#include "data.hpp"
using namespace std;

extern struct Tutor* tutor_array;
extern int array_size;

int get_tutor_array_size() {
	return array_size;
}

void create_new_tutor(int tutor_ID, string name, string date_joined, string date_terminated, double hourly_rate, string phone, string address, int centre_code, string centre_name, int subject_code, string subject_name, int rating){
	int tutor_array_size = get_tutor_array_size();
	tutor_array[tutor_array_size].tutor_ID = tutor_ID;
    tutor_array[tutor_array_size].name = name;
    tutor_array[tutor_array_size].date_joined = date_joined;
    tutor_array[tutor_array_size].date_terminated = date_terminated;
    tutor_array[tutor_array_size].hourly_rate = hourly_rate;
}

void add_new_tutor() {
	
}