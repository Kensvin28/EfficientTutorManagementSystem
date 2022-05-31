#include "functions.hpp"
#include "display.hpp"
#include <iostream>
#include <string>
using namespace std;
Tutor* head;
Tutor* tail;
Staff* staff_head;
Staff* staff_tail;

// void login_menu()
// {
//     int choice = 0;
//     cout << "1. Login" << endl;
//     cout << "2. Register" << endl;
//     cout << "3. Exit" << endl;
//     cout << "Choice: ";
//     cin >> choice;
//     if (choice == 3)
//     {
//         cout << "Good bye";
//         exit;
//     }else if (choice == 1) {
//         login();
//     }else if (choice == 2) reg();
//     else cout << "Invalid input";
// }

int main(){
    // int choice = 0;
    // do{
    //     cout << "1. Login" << endl;
    //     cout << "2. Register" << endl;
    //     cout << "3. Exit" << endl;
    //     cout << "Choice: ";
    //     cin >> choice;
    //     if (choice == 3)
    //     {
    //         cout << "Good bye";
    //         exit;
    //     }else if (choice == 1) {
    //         int flag;
    //         int staff_id;
    //         string staff_password;
    //         do
    //         {
    //             cout << "\nStaff Login" << endl;
    //             display_separator();
    //             cout << endl;
    //             cout << "Staff ID: ";
    //             cin >> staff_id;
    //             cout << "Password: ";
    //             cin >> staff_password;
    //             flag = login_checker(staff_id, staff_password);
    //         } while (flag == 0);
    //     }else if (choice == 2) reg();
    //     else cout << "Invalid input";
    // }while (true);
    
    int choice;
    do {
        choice = 0;
        display_separator();
        cout << " eXcel Tuition Centre ";
        display_separator();
        reg();
        login();

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
            // return 0
        }
        //else if (choice == 1) add_new_tutor();
        //else if (choice == 2) display();
        else if (choice == 3) search();
        else if (choice == 4) sort();
        //else if (choice == 5) modify();
        //else if (choice == 6) delete_tutor();
        else if (choice == 7) report();
        else cout << "Invalid input";
    } while (true);
    return 0;
}

