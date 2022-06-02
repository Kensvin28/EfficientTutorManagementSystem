#include <iostream>
#include "data.hpp"
using namespace std;

extern struct Tutor* head;
extern struct Tutor* tail;

void display_detailed_current(Tutor* node){
	Tutor* current = node;
	cout << "| " << current->tutor_ID << "| " << current->name << "| " << current->date_joined << "| " + current->date_terminated << "| " << current->hourly_rate << "| " << current->phone <<
		"| " << current->address << "| " << current->centre_code << "| " << current->centre_name << "| " << current->subject_code << "| " << current->subject_name << "| " << current->rating << "| " << endl;
	current = current->next;
	return;
}
void display_separator() {
	cout << string(25, '=');
}

void display_sorted(Tutor* head) {
	Tutor* current = head;
	while (current != NULL) {
		cout << "| " << current->tutor_ID << "| " << current->name << "| " << current->date_joined << "| " + current->date_terminated << "| " << current->hourly_rate << "| " << current->phone <<
		"| " << current->address << "| " << current->centre_code << "| " << current->centre_name << "| " << current->subject_code << "| " << current->subject_name << "| " << current->rating << "| " << endl;
		current = current->next;
	}
}