#include "functions.hpp"
#include "display.hpp"
#include <iostream>
#include <string>
using namespace std;
Tutor* head;
Tutor* tail;
Staff* staff_head;
Staff* staff_tail;

void main_menu() {
    int choice;
    bool logged_in = false;
    do {
        choice = 0;
        system("CLS");
        display_separator();
        cout << " eXcel Tuition Centre ";
        display_separator();
        cout << endl;

        //log in if not logged in
        if (!logged_in) {
            //reg();
            logged_in = login();
        }

        system("CLS");
        display_separator();
        cout << " eXcel Tuition Centre ";
        display_separator();
        cout << endl;
        cout << "1. Add new tutor" << endl;
        cout << "2. Display all tutors" << endl;
        cout << "3. Search tutor" << endl;
        cout << "4. Sort tutor" << endl;
        cout << "5. Modify tutor" << endl;
        cout << "6. Delete tutor" << endl;
        cout << "7. Report" << endl;
        cout << "8. Log out" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 8) {
            cout << "Good bye!";
            return;
        }

        //else if (choice == 1) add_new_tutor();
        //else if (choice == 2) display();
        else if (choice == 3) search();
        else if (choice == 4) sort();
        //else if (choice == 5) modify();
        //else if (choice == 6) delete_tutor();
        else if (choice == 7) report();
        else cout << "Invalid input!" << endl << endl;
    } while (true);
}

void create_dummy_records() {
    //Staff* new_node = add_new_staff_node(staff_id, staff_name, centre_code, staff_position, staff_password);
    //insert_to_end(new_node);
}

int main() {
    main_menu();
    return 0;
}