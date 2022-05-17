#include <data.hpp>
#include <io.hpp>

void sort() {
	int choice;
	Tutor* sort_node;
	do {
		display_separator();
		cout << "Sort and Display Tutors";
		cout << "1. Sort by ID";
		cout << "2. Sort by Hourly Rate";
		cout << "3. Sort by Rating";
		cout << "0. Return";
		cin >> choice;

		Tutor* new_head = copy_list(head);

		if (choice == 1) {
			sort_node = merge_sort(new_head, 1);
			print_sort_id(sort_node);
		}
		else if (choice == 2) {
			sort_node = merge_sort(new_head, 2);
			print_sort_hourly(sort_node);
		}
		else if (choice == 3) {
			sort_node = merge_sort(new_head, 3);
			print_sort_rating(sort_node);
		}
		else if (choice != 0) {
			cout << "Invalid input!";
		}
	} while (choice >= 0 && choice <= 3);
}

Tutor* copy_list(Tutor* head) {
	return recursive_copy(head, NULL);
}

Tutor* recursive_copy(Tutor* current_node, Tutor* previous_node) {
	if (head == NULL) return head;

	Tutor* new_node;
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
}

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

Tutor* merge_sort(Tutor* head, int type) {
	if (!head || !head->next) return head;
	
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

void print_sort_id(Tutor* head) {
	Tutor* temp = head;
	cout << "Printing tutor sorted by ID: ";
	while (head) {
		Tutor* current = head;
		//change format later
		cout << current->tutor_ID << " | " << current->name << " | " << current ->date_joined << " | " << current->date_terminated << " | " << current->hourly_rate << " | " << current->phone << " | " << current->address << " | " << current->centre_code << " | " << current->centre_name << " | " << current->subject_code << " | " << current->subject_name << " | " << current->rating;
		//what is the purpose of this
		temp = head;
		head = head->next;
	}
}

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

void print_sort_hourly(Tutor* head) {
	Tutor* temp = head;
	cout << "Printing tutor sorted by ID: ";
	while (head) {
		Tutor* current = head;
		//change format later
		cout << current->tutor_ID << " | " << current->name << " | " << current->date_joined << " | " << current->date_terminated << " | " << current->hourly_rate << " | " << current->phone << " | " << current->address << " | " << current->centre_code << " | " << current->centre_name << " | " << current->subject_code << " | " << current->subject_name << " | " << current->rating;
		//what is the purpose of this
		temp = head;
		head = head->next;
	}
}

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

void print_sort_rating(Tutor* head) {
	Tutor* temp = head;
	cout << "Printing tutor sorted by ID: ";
	while (head) {
		Tutor* current = head;
		//change format later
		cout << current->tutor_ID << " | " << current->name << " | " << current->date_joined << " | " << current->date_terminated << " | " << current->hourly_rate << " | " << current->phone << " | " << current->address << " | " << current->centre_code << " | " << current->centre_name << " | " << current->subject_code << " | " << current->subject_name << " | " << current->rating;
		//what is the purpose of this
		temp = head;
		head = head->next;
	}
}