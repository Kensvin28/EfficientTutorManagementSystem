#include "data.hpp"
#include "display.hpp"
#include <iostream>
using namespace std;
extern struct Tutor* head;
extern struct Tutor* tail;


//create and return new duplicate nodes
Tutor* recursive_copy(Tutor* current_node, Tutor* previous_node) {
	if (current_node == NULL) return NULL;
	else {
		Tutor* new_node = new Tutor;
		new_node->tutor_ID = current_node->tutor_ID;
		new_node->name = current_node->name;
		new_node->date_joined = current_node->date_joined;
		new_node->date_terminated = current_node->date_terminated;
		new_node->hourly_rate = current_node->hourly_rate;
		new_node->phone = current_node->phone;
		new_node->address = current_node->address;
		new_node->centre_code = current_node->centre_code;
		new_node->centre_name = current_node->centre_name;
		new_node->subject_code = current_node->subject_code;
		new_node->subject_name = current_node->subject_name;
		new_node->rating = current_node->rating;
		new_node->prev = previous_node;
		new_node->next = recursive_copy(current_node->next, new_node);
		return new_node;
	}
}

//copy linked list
Tutor* copy_list(Tutor* head) {
	return recursive_copy(head, NULL);
}

//TODO can you comment on these
Tutor* split(Tutor* head) {
	Tutor* fast = head;
	Tutor* slow = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Tutor* temp = slow->next;
	slow->next = NULL;
	return temp;
}

//merge sort by id
Tutor* merge_id(Tutor* first, Tutor* second) {
	if (first == NULL) return second;
	if (second == NULL) return first;

	if (first->tutor_ID < second->tutor_ID) {
		first->next = merge_id(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else {
		second->next = merge_id(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

//merge sort by hourly rate
Tutor* merge_hourly(Tutor* first, Tutor* second) {
	if (first == NULL) return second;
	if (second == NULL) return first;

	if (first->hourly_rate < second->hourly_rate) {
		first->next = merge_hourly(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else {
		second->next = merge_hourly(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

//merge sort by rating
Tutor* merge_rating(Tutor* first, Tutor* second) {
	if (first == NULL) return second;
	if (second == NULL) return first;

	if (first->rating < second->rating) {
		first->next = merge_rating(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else {
		second->next = merge_rating(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

//general merge sort
Tutor* merge_sort(Tutor* head, int type) {
	if (head == NULL || head->next == NULL) return head;

	//modified
	if (type >= 1 && type <= 3) {
		Tutor* second = split(head);
		head = merge_sort(head, type);
		second = merge_sort(second, type);
		switch (type) {
		case 1:
			merge_id(head, second);
			break;
		case 2:
			merge_hourly(head, second);
			break;
		case 3:
			merge_rating(head, second);
		}
	}
}

//TODO can be combined into the display section
void display_sorted(Tutor* head) {
	Tutor* current = head;
	while (current != NULL) {
		//TODO change format later
		cout << current->tutor_ID << " | " << current->name << " | " << current->date_joined << " | " << current->date_terminated << " | " << current->hourly_rate << " | " << current->phone << " | " << current->address << " | " << current->centre_code << " | " << current->centre_name << " | " << current->subject_code << " | " << current->subject_name << " | " << current->rating << endl;
		current = current->next;
	}
}


//sort menu
void sort() {
	int choice;
	Tutor* sort_node;
	do {
			display_separator();
			cout << "Sort and Display Tutors";
			display_separator();
			cout << endl;
		do {
			cout << "1. Sort by ID" << endl;
			cout << "2. Sort by Hourly Rate" << endl;
			cout << "3. Sort by Rating" << endl;
			cout << "0. Return" << endl;
			cout << "Choice: ";
			cin >> choice;
		} while (choice < 0 && choice > 3 || cin.fail());

		Tutor* new_head = copy_list(head);

		if (choice == 1) {
			sort_node = merge_sort(new_head, 1);
			cout << "Printing tutor sorted by ID: " << endl;
			display_sorted(sort_node);
		}
		else if (choice == 2) {
			sort_node = merge_sort(new_head, 2);
			cout << "Printing tutor sorted by hourly rate ascendingly: " << endl;
			display_sorted(sort_node);
		}
		else if (choice == 3) {
			sort_node = merge_sort(new_head, 3);
			cout << "Printing tutor sorted by rating ascendingly: " << endl;
			display_sorted(sort_node);
		}
		else if (choice != 0) {
			cout << "Invalid input!" << endl;
		}
		else {
			cout << endl;
			cin.get();
			return;
		}
	} while (choice != 0);
}