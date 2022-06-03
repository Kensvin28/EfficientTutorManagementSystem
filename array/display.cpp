#include <iostream>
#include "data.hpp"
#include "search.hpp"
using namespace std;

extern int tutor_array_size;
extern struct Tutor* tutor_array;

void display_detailed(Tutor* tutor_array, int index){
	cout << "| " << tutor_array[index].tutor_ID << "| " << tutor_array[index].name << "| " << tutor_array[index].date_joined << "| " << tutor_array[index].date_terminated << "| " << tutor_array[index].hourly_rate << "| " << tutor_array[index].phone <<
		"| " << tutor_array[index].address << "| " << tutor_array[index].centre_code << "| " << tutor_array[index].centre_name << "| " << tutor_array[index].subject_code << "| " << tutor_array[index].subject_name << "| " << tutor_array[index].rating << "| " << endl;
}
void display_separator() {
	cout << string(25, '=');
}

void display_sorted(Tutor* tutor_array) {
	for (int i = 0; i < tutor_array_size; i++) {
		cout << "| " << tutor_array[i].tutor_ID << "| " << tutor_array[i].name << "| " << tutor_array[i].date_joined << "| " << tutor_array[i].date_terminated << "| " << tutor_array[i].hourly_rate << "| " << tutor_array[i].phone <<
			"| " << tutor_array[i].address << "| " << tutor_array[i].centre_code << "| " << tutor_array[i].centre_name << "| " << tutor_array[i].subject_code << "| " << tutor_array[i].subject_name << "| " << tutor_array[i].rating << "| " << endl;
	}
}

void display(){
	int index = -1, choice = 0;

	while (true) {
		system("cls");
		display_separator();
		cout << "Display";
		display_separator();
		cout << endl;
		display_sorted(tutor_array);
		cout << endl;
		cout << "Input the index of a tutor record to view more or input 0 to go back to the main menu:  ";
		cin >> index;
		//reduce index so that it is suitable with the array index
		validate_number();

		if (index == 0) return;

		while (index < 0 || index > tutor_array_size) {
			cout << "Invalid input!" << endl;
			cout << "Input the index of a tutor record to view more or input 0 to go back to main menu:  ";
			cin >> index;
		}
		index--;

		do {
			system("cls");
			display_separator();
			cout << "Detailed Records";
			display_separator();
			cout << endl;
			display_detailed(tutor_array, index);
			if (index > 0) {
				cout << "1. Previous record" << endl;
			}
			if (index < tutor_array_size-1) {
				cout << "2. Next record" << endl;
			}
			cout << "0. Return" << endl;
			cout << "Choice: ";
			cin >> choice;
			validate_number();

			cout << endl;
			if (choice == 1) {
				if (index > 0) {
					index--;
					display_detailed(tutor_array, index);
				}
				else {
					cout << "Reached beginning of list" << endl;
				}
			}
			else if (choice == 2) {
				if (index < tutor_array_size - 1) {
					index++;
					display_detailed(tutor_array, index);
				}
				else {
					cout << "Reached end of list already" << endl;
				}
			}
			else if (choice != 0) {
				cout << "Invalid input";
			}
		} while (choice != 0);
	}
}