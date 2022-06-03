#include <iostream>
#include "data.hpp"
using namespace std;

//extern struct Tutor clone_array[100];
//extern struct Tutor tutor_array[100];

void display_detailed(Tutor* tutor_array, int index){
	cout << "| " << tutor_array[index].tutor_ID << "| " << tutor_array[index].name << "| " << tutor_array[index].date_joined << "| " + tutor_array[index].date_terminated << "| " << tutor_array[index].hourly_rate << "| " << tutor_array[index].phone <<
		"| " << tutor_array[index].address << "| " << tutor_array[index].centre_code << "| " << tutor_array[index].centre_name << "| " << tutor_array[index].subject_code << "| " << tutor_array[index].subject_name << "| " << tutor_array[index].rating << "| " << endl;
}
void display_separator() {
	cout << string(25, '=');
}

void display(){
	
}