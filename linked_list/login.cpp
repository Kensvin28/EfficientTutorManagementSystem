#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "display.hpp"
#include "data.hpp"
extern struct Staff* head;
extern struct Staff* tail;

using namespace std;

Staff* add_new_staff_node(int staff_id, string staff_name, int centre_code, string staff_position, string staff_password)
{
    Staff* new_node = new Staff;
    new_node->staff_id = staff_id;
    new_node->staff_name = staff_name;
    new_node->centre_code = centre_code;
    new_node->staff_position = staff_position;
    new_node->staff_password = staff_password;
    new_node->next;
    new_node->prev;

    return new_node;
}

void insert_to_end(Staff* new_node)
{
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
}

void reg()
{
    int i = 1;
    int staff_id, centre_code;
    string staff_name, staff_position, staff_password;
    head = tail = NULL;
    cout << "Staff Registration" << endl;
    display_separator();
    cout << endl;
    do{
        cout << "Enter Staff ID: ";
        cin >> staff_id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Staff Name: ";
        getline(cin, staff_name);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Staff Position: ";
        getline(cin, staff_position);
        cout << "Enter Centre Code: ";
        cin >> centre_code;
        cout << "Enter Password: ";
        cin >> staff_password;
        //8 character or greater password validation
        while (staff_password.length() < 8)
        {
            cout << "\n Password needs to be 8 characters or greater!" << endl << "Enter Password: ";
            cin >> staff_password;
            if(staff_password.length() >= 8)
            {
                break;
            }
        };
        Staff* new_node = add_new_staff_node(staff_id, staff_name, centre_code, staff_position, staff_password);
        insert_to_end(new_node);
        cout << "Type 0 to end / other numbers to add more: ";
        cin >> i;
        if(i == 0)
        {
            return;
        }
    }while(i != 0);
}

int login_checker(int staff_id, string staff_password)
{
    if(staff_id <= tail->staff_id/2)
    {
        if(head == NULL)
        {
            return 0;
        }
        Staff* current_ptr = head;
        do{
            if(current_ptr->staff_id == staff_id)
            {
                if (current_ptr->staff_password == staff_password)
                {
                    return 1;
                }
            }
            current_ptr = current_ptr->next;
        }while(current_ptr != NULL);
    }
    else {
        if(tail == NULL)
        {
            return 0;
        }
        Staff* current_ptr = tail;
        do{
            if(current_ptr->staff_id == staff_id)
            {
                if (current_ptr->staff_password == staff_password)
                {
                    return 1;
                }
            }
            current_ptr = current_ptr->prev;
        }while(current_ptr != NULL);
    }
}

void login()
{
    int flag = 0;
    int staff_id;
    string staff_password;

    while(flag == 0)
    {
        cout << "Staff Login" << endl;
        display_separator();
        cout << endl;
        cout << "Staff ID: ";
        cin >> staff_id;
        cout << "Password: ";
        cin >> staff_password;
        flag = login_checker(staff_id, staff_password);
        if(flag == 0)
        {
            cout << "Invalid Login Credentials. Please try again.";
        }else{
            cout << "Login Successful";
            return;
        }
    }
}

// void login_menu()
// {
//     int choice = 0;
//     cout << "1. Login" << endl;
//         cout << "2. Register" << endl;
//         cout << "3. Exit" << endl;
//         if (choice == 3)
//         {
//             cout << "Good bye";
//             return 0;
//         }else if (choice == 1) reg();
//         else if (choice == 2) login();
//         else cout << "Invalid input";
// }