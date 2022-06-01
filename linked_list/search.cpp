#include "data.hpp"
#include "sort.hpp"
#include "display.hpp"
#include <iostream>
#include <limits>
using namespace std;
extern struct Tutor* head;
extern struct Tutor* tail;

//search tutor by tutor ID
void search_by_tutor_id(int tutor_id) {
    //if head points to null, list is empty
    if (head == NULL) {
        cout << "Record with ID " << tutor_id << " is not found" << endl;
        return;
    }
       
    //if tutor node is closer to head
    if (tutor_id <= tail->tutor_ID / 2) {
        Tutor* current = head;
        while (current != NULL) {
            //display search result if match is found
            if (current->tutor_ID == tutor_id) {
                display_detailed_current(current);
                return;
            }
            //traverse linked list
            current = current->next;
        }
    }
    else {
        Tutor* current = tail;
        while (current != NULL) {
            //display search result if match is found
            if (current->tutor_ID == tutor_id) {
                display_detailed_current(current);
                return;
            }
            //traverse linked list
            current = current->prev;
        }
        
    }
    //ID not found
    cout << "Record with ID " << tutor_id << " is not found" << endl;
}

void search_by_tutor_rating(int rating) {
    //TODO change so that it does not affect original data, temp linked_list_size
    //Tutor* new_head = copy_list(head);
    merge_sort(head, 3);

    //if head points to null, list is empty 
    if (head == NULL) {
        cout << "Record with the rating of " << rating << " is not found" << endl;
        return;
    }

    //if node is closer to head
    if (rating <= 3) {
        Tutor* current = head;
        //traverse linked list
        while (current != NULL) {
            //if match is found
            if (current->rating == rating) {
                //display matching records
                while (current != NULL && current->rating == rating) {
                    display_detailed_current(current);
                    current = current->next;
                }
                return;
            }
            current = current->next;
        }
    }
    //if node is closer to tail
    else {
        Tutor* current = tail;
        //traverse linked list
        while (current != NULL) {
            //if match is found
            if (current->rating == rating) {
                //display matching records
                while (current->rating == rating && current != NULL) {
                    display_detailed_current(current);
                    current = current->prev;
                }
                return;
            }
            current = current->prev;
        }
    }
    //no record with the specified rating
    cout << "Record with the rating of " << rating << " is not found" << endl;
}

//validate choice
void validate_int() {
    while (cin.fail()) {
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//search menu
void search(){
    int choice;
    do {
        system("cls");
        cin.clear();
        display_separator();
        cout << "Search Tutor";
        display_separator();
        cout << endl;
        cout << "1. Search tutor by tutor ID" << endl;
        cout << "2. Search tutor by rating" << endl;
        cout << "0. Return to main menu" << endl;
        cin >> choice;

        //search tutor by tutor ID
        if (choice == 1) {
            int id;
            do {
                cout << "Input tutor ID to be searched: ";
                cin >> id;
                search_by_tutor_id(id);
                validate_int();
                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
                validate_int();
            } while (choice == 1);
        }
        //search tutor by rating
        else if (choice == 2) {
            int rating;
            do {
                cout << "Input tutor rating to be searched: ";
                cin >> rating;
                validate_int();
                search_by_tutor_rating(rating);
                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
                validate_int();
            } while (choice == 1);
        }
        cout << endl;
    } while(choice < 0 && choice > 2);
}