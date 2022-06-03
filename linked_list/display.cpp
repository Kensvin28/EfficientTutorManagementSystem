#include <iostream>
#include "data.hpp"
#include "display.hpp"
using namespace std;

extern struct Tutor* head;
extern struct Tutor* tail;
extern int linked_list_size;

void display_summary_from_beginning(Tutor* current) {
	int index = 1;
	while (current != NULL) {
		cout << "| " << current->tutor_ID << "| " << current->name << "| " << current->centre_name << "| " << current->subject_name << "| " << current->rating << "| " << endl;
		current = current->next;
		index++;
	}
}

void display_detailed_current(Tutor* current) {
	cout << "| " << current->tutor_ID << "| " << current->name << "| " << current->date_joined << "| " << current->date_terminated << "| " << current->hourly_rate << "| " << current->phone <<
		"| " << current->address << "| " << current->centre_code << "| " << current->centre_name << "| " << current->subject_code << "| " << current->subject_name << "| " << current->rating << "| " << endl;
	current = current->next;
}

void display(){
	Tutor* current;
	int position, index, choice = 0;
	current = head;

	while (true) {
		system("cls");
		display_separator();
		cout << "Display";
		display_separator();
		cout << endl;
		display_summary_from_beginning(head);
		cout << endl;
		cout << "Input the index of a tutor record to view more or input 0 to go back to the main menu:  ";
		cin >> position;

		while (position < 0 || position > linked_list_size) {
			cout << "Invalid input!" << endl;
			cout << "Input the index of a tutor record to view more or input 0 to go back to main menu:  ";
			cin >> position;
		}

		if (position == 0) return;

		if (position <= linked_list_size / 2) {
			current = head;
			index = 1;
			while (index < position) {
				current = current->next;
				index++;
			}
		}
		else {
			current = tail;
			index = linked_list_size;
			while (index < position) {
				current = current->prev;
				index--;
			}
		}

		do {
			system("cls");
			display_separator();
			cout << "Detailed Records";
			display_separator();
			cout << endl;
			display_detailed_current(current);
			if (current->prev != NULL) {
				cout << "1. Previous record" << endl;
			}
			if (current->next != NULL) {
				cout << "2. Next record" << endl;
			}
			cout << "0. Return" << endl;
			cout << "Choice: ";
			cin >> choice;
			cout << endl;

			if (choice == 1) {
				if (current->prev != NULL) {
					current = current->prev;
				}
				else {
					cout << "Reached beginning of list already" << endl;
				}
			}
			else if (choice == 2) {
				if (current->next != NULL) {
					current = current->next;
					
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