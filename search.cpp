#include <io.hpp>
#include <data.hpp>
#include <sort.hpp>
#include <display.hpp>

void search(){
    int choice;
    do {
        display_separator();
        cout << "Search Tutor";
        display_separator();
        cout << endl;
        cout << "1. Search tutor by tutor ID" << endl;
        cout << "2. Search tutor by rating" << endl;
        cout << "0. Return to main menu" << endl;
        cin >> choice;

        if (choice == 1) {
            int id;
            do {
                cout << "Input tutor ID to be searched: ";
                cin >> id;
                search_by_tutor_id(id);
                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
            } while (choice != 1);
        }
        else if (choice == 2) {
            int rating;
            do {
                cout << "Input tutor rating to be searched: ";
                cin >> rating;
                search_by_tutor_rating(rating);
                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
            } while (choice != 1);
        }
        else if (choice != 0) {
            cout << "Invalid input";
        }
    } while(choice >= 0 && choice <= 2);
}

void search_by_tutor_id(int tutor_id) {
    if (head == NULL) return;

    if (tutor_id <= tail->tutor_ID / 2) {
        Tutor* current = head;
        while (current != NULL) {
            if (current->tutor_ID == tutor_id) {
                display_detailed_current(current);
                return;
            }
            current = current->next;
        }
        cout << "Record with ID " << tutor_id << " not found" << endl;
    }
    else {
        Tutor* current = tail;
        while (current != NULL) {
            if (current->tutor_ID == tutor_id) {
                display_detailed_current(current);
                return;
            }
            current = current->prev;
        }
        cout << "Record with ID " << tutor_id << " not found" << endl;
    }
}

void search_by_tutor_rating(int rating) {
    merge_sort(head, 3);
    if (head == NULL) return;

    if (rating <= 3) {
        Tutor* current = head;
        while (current != NULL) {
            if (current->rating == rating) {
                while (current->rating == rating) {
                    display_detailed_current(current);
                    current = current->next;
                }
                return;
            }
            current = current->next;
        }
    }
    else {
        Tutor* current = tail;
        while (current != NULL) {
            if (current->rating == rating) {
                while (current->rating == rating) {
                    display_detailed_current(current);
                    current = current->prev;
                }
                return;
            }
            current = current->prev;
        }
    }
}