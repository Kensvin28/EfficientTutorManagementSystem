#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "display.hpp"
#include "data.hpp"
extern int staff_list_size;
extern struct Staff* staff_head;
extern struct Staff* staff_tail;
struct Staff* current_logged_in;

using namespace std;

//add new staff node to the doubly linked list
Staff* add_new_staff_node(int staff_id, string staff_name, int centre_code, string staff_position, string staff_password)
{
    Staff* new_node = new Staff;
    new_node->staff_id = staff_id;
    new_node->staff_name = staff_name;
    new_node->centre_code = centre_code;
    new_node->staff_position = staff_position;
    new_node->staff_password = staff_password;
    new_node->next = NULL;
    new_node->prev = NULL;

    staff_list_size++;
    return new_node;
}

//insert new staff node to the end of doubly linked list
void insert_to_end(Staff* new_node)
{
	if (staff_head == NULL)
	{
        staff_head = staff_tail = new_node;
	}
	else
	{
        staff_tail->next = new_node;
        new_node->prev = staff_tail;
        staff_tail = new_node;
	}
}

//auto assign id
int assign_id()
{
    return staff_list_size + 1;
}

//register function
void reg()
{
    int i = 1, check = 0;
    int staff_id, centre_code;
    string staff_name, staff_position, staff_password;
    staff_head = staff_tail = NULL;
    cout << "\nStaff Registration" << endl;
    display_separator();
    cout << endl;
    do{
        int staff_id = assign_id();
        cout << "Staff ID: " << staff_id << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Staff Name: ";
        getline(cin, staff_name);
        cout << "Enter Staff Position: ";
        getline(cin, staff_position);
        do {
            cin.clear();
            cout << "Enter Centre Code: ";
            cin >> centre_code;
            if ((centre_code < 1 && centre_code > 5) || cin.fail()) {
                cout << "Invalid input" << endl;
                cout << "Enter Centre Code: ";
                cin >> centre_code;
            }
        } while ((centre_code < 1 && centre_code > 5) || cin.fail());
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
        cout << "\n" << staff_id << "| " << staff_name << "| " << centre_code << "| " << staff_position << "| " << staff_password << endl;
        cout << "Type 0 to end / other numbers to add more: ";
        cin >> i;
        if(i == 0)
        {
            return;
        }
    }while(i != 0);
}

//login validation
int login_checker(int staff_id, string staff_password)
{
    if (staff_head == NULL || staff_tail == NULL) {
        cout << "Staff record is empty." << endl;
        return 0;
    }

    if(staff_id <= staff_tail->staff_id/2)
    {
        Staff* current_ptr = staff_head;
        do{
            if(current_ptr->staff_id == staff_id)
            {
                if (current_ptr->staff_password == staff_password)
                {
                    current_logged_in = current_ptr;
                    return 1;
                } else {
                    cout << "Password not matching" << endl;
                }
            }
            current_ptr = current_ptr->next;
        }while(current_ptr != NULL);
    }
    else {
        Staff* current_ptr = staff_tail;
        do{
            if(current_ptr->staff_id == staff_id)
            {
                if (current_ptr->staff_password == staff_password)
                {
                    current_logged_in = current_ptr;
                    return 1;
                }
                else {
                    cout << "Password not matching" << endl;
                }
            }
            current_ptr = current_ptr->prev;
        }while(current_ptr != NULL);
    }
    return 0;
}

//login function
bool login()
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
        while(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Staff ID: ";
            cin >> staff_id;
        }

        cout << "Password: ";
        cin >> staff_password;
        flag = login_checker(staff_id, staff_password);
        //TODO remove login override
        // flag = 1;
        if (flag == 0)
        {
            cout << "Invalid Login Credentials. Please try again." << endl << endl;
        }
        else {
            cout << "Login Successful" << endl;
            return true;
        }
    }
    return false;
}