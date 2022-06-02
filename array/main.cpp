#include "data.hpp"
#include "functions.hpp"
#include "display.hpp"
#include <iostream>
using namespace std;

struct Tutor* clone_array = new Tutor[100];
struct Tutor* tutor_array = new Tutor[100];
struct Staff* staff_array = new Staff[100];
int tutor_array_size = 0;
int staff_array_size = 0;

void main_menu();
void login_menu();
void create_dummy_records();

int main(){
    create_dummy_records();
    login_menu();
    return 0;
}

void create_dummy_records() {
    int staff_id = 1;
    string staff_name = "admin";
    string staff_position = "ADMIN";
    int centre_code = 1;
    string staff_password = "qwer1234";
    add_new_staff(staff_id, staff_name, centre_code, staff_position, staff_password);

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

    create_new_tutor(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);

    tutor_ID = 2;
    name = "Broda";
    date_joined = "01/06/2002";
    date_terminated = "";
    hourly_rate = 53.33;
    phone = "9649007418";
    address = "602 Orin Drive";
    centre_code = 101;
    centre_name = "Bukit Jalil";
    subject_code = 9;
    subject_name = "Physics";
    rating = 1;

    create_new_tutor(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
}

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
    do{
        choice = 0;
        system("CLS");
        display_separator();
        cout << " eXcel Tuition Centre ";
        display_separator();
        cout << endl;

        //log in if not logged in
        if (!logged_in) {
            logged_in = login();
        }

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
            cout << "Good bye";
            login_menu();
        }
        else if (choice == 1) add_new_tutor();
        else if (choice == 2) display();
        else if (choice == 3) search();
        else if (choice == 4) sort();
        else if (choice == 5) modify();
        else if (choice == 6) remove();
        else if (choice == 7) report();
        else cout << "Invalid input";
    }while(true);
}