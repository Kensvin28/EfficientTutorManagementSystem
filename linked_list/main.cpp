#include "functions.hpp"
#include "display.hpp"
#include "login.hpp"
#include "add.hpp"
#include <iostream>
#include <string>
using namespace std;
Tutor* head;
Tutor* tail;
Staff* staff_head;
Staff* staff_tail;
int staff_list_size = 0;
int linked_list_size = 0;

void login_menu(){
    int choice;
    do {
        choice = 0;
        system("CLS");
        display_separator();
        cout << " eXcel Tuition Centre ";
        display_separator();
        cout << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        if(choice == 3){
            cout << "Goodbye!";
            exit(0);
        } else if (choice == 1) reg();
        else if (choice == 2) main_menu();
    } while (true);
}

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
            login_menu();
            // return;
        }

        else if (choice == 1) add_new_tutor();
        else if (choice == 2) display();
        else if (choice == 3) search();
        else if (choice == 4) sort();
        else if (choice == 5) modify();
        else if (choice == 6) remove();
        else if (choice == 7) report();
        else cout << "Invalid input!" << endl << endl;
    } while (true);
}

//TODO: remove temp insert node
void insert_to_tutor_end(Tutor* new_node) {
    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    linked_list_size++;
}

void create_dummy_records() {

    int staff_id = 1;
    string staff_name = "admin";
    string staff_position = "ADMIN";
    int centre_code = 1;
    string staff_password = "qwer1234";
    Staff* new_node = add_new_staff_node(staff_id, staff_name, centre_code, staff_position, staff_password);
    insert_to_end(new_node);

    int tutor_ID = 1;
    string name = "Broddie";
    string date_joined = "01/01/2000";
    string date_terminated = "";
    double hourly_rate = 53.33;
    string phone = "9649007418";
    string address = "602 Orin Drive";
    centre_code = 101;
    string centre_name = "Bukit Jalil";
    int subject_code = 9;
    string subject_name = "Physics";
    int rating = 3;

    Tutor* t_new_node = create_new_tutor_node(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
    insert_to_tutor_end(t_new_node);

    tutor_ID = 2;
    name = "Broda";
    date_joined = "08/06/2002";
    date_terminated = "";
    hourly_rate = 53.33;
    phone = "9649007418";
    address = "602 Orin Drive";
    centre_code = 101;
    centre_name = "Bukit Jalil";
    subject_code = 9;
    subject_name = "Physics";
    rating = 1;

    t_new_node = create_new_tutor_node(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
    insert_to_tutor_end(t_new_node);
}

int main() {
    create_dummy_records();
    login_menu();
    return 0;
}