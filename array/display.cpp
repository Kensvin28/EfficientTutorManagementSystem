#include <iostream>
#include "data.hpp"
using namespace std;

extern int tutor_array_size;

void display_detailed(Tutor* tutor_array, int index){
	cout << "| " << tutor_array[index].tutor_ID << "| " << tutor_array[index].name << "| " << tutor_array[index].date_joined << "| " << tutor_array[index].date_terminated << "| " << tutor_array[index].hourly_rate << "| " << tutor_array[index].phone <<
		"| " << tutor_array[index].address << "| " << tutor_array[index].centre_code << "| " << tutor_array[index].centre_name << "| " << tutor_array[index].subject_code << "| " << tutor_array[index].subject_name << "| " << tutor_array[index].rating << "| " << endl;
}
void display_separator() {
	cout << string(25, '=');
}

void display(){
	
}

void display_sorted(Tutor* tutor_array) {
	for (int i = 0; i < tutor_array_size; i++) {
		cout << "| " << tutor_array[i].tutor_ID << "| " << tutor_array[i].name << "| " << tutor_array[i].date_joined << "| " << tutor_array[i].date_terminated << "| " << tutor_array[i].hourly_rate << "| " << tutor_array[i].phone <<
			"| " << tutor_array[i].address << "| " << tutor_array[i].centre_code << "| " << tutor_array[i].centre_name << "| " << tutor_array[i].subject_code << "| " << tutor_array[i].subject_name << "| " << tutor_array[i].rating << "| " << endl;
	}
}