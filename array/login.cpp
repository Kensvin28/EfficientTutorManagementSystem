#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
// #include "sort.hpp"
#include "display.hpp"
#include "data.hpp"
extern struct Staff* clone_array;
extern struct Staff* staff_array;
extern int staff_array_size;
struct Staff current_logged_in;

using namespace std;

void add_new_staff(int staff_id, string staff_name, int centre_code, string staff_position, string staff_password)
{
    staff_array[staff_array_size].staff_id = staff_id;
    staff_array[staff_array_size].staff_name = staff_name;
    staff_array[staff_array_size].centre_code = centre_code;
    staff_array[staff_array_size].staff_position = staff_position;
    staff_array[staff_array_size].staff_password = staff_password;
    staff_array_size++;
}

// void resize_array(Staff* staff_array, int records){
//     // clone_array[] = clone_array[staff_array_size*2];
    
//     //copy array
//     for(int i = 0; i < staff_array_size; i++){
//         clone_array[i] = staff_array[i];
//     }
//  }

void reg(){
    int choice = 1, i =0;
    int staff_id, centre_code;
    string staff_name, staff_position, staff_password;
    cout << "\nStaff Registration" << endl;
    display_separator();
    cout << endl;
    do{
        int staff_id = staff_array_size + 1;
        cout << "Staff ID: " << staff_id << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Staff Name: ";
        getline(cin, staff_name);
        cout << "Enter Staff Position: ";
        getline(cin, staff_position);
        do {
            cin.clear();
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Centre Code (1-5): ";
            cin >> centre_code;
            if ((centre_code < 1 && centre_code > 5) || cin.fail()) {
                cout << "Invalid input" << endl;
                cout << "Enter Centre Code(1-5): ";
                cin >> centre_code;
                // cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

        add_new_staff(staff_id, staff_name, centre_code, staff_position, staff_password);

        cout << "\n" << staff_id << "| " << staff_name << "| " << centre_code << "| " << staff_position << "| " << staff_password << endl;
        cout << "Type 0 to end / other numbers to add more: ";
        cin >> i;
        if(i == 0)
        {
            return;
        }
    }while(i != 0);
}

// int search_by_staff_id(Staff* input_array, int low, int high, int id){
//     if (low <= high) {
//         int middle = (low + high)/2;
//         //if found
//         if (input_array[middle].staff_id == id) return middle;
//         //if id is lower, call recursive function and search lower
//         else if (input_array[middle].staff_id < id) return search_by_staff_id(input_array, low, middle - 1, id);
//         //if id is higher, call recursive function and search higher
//         else return search_by_staff_id(input_array, middle + 1, high, id);
//     }
//     return -1;
// }

int login_checker(int staff_id, string staff_password)
{
    int index;
    // int index = search_by_staff_id(staff_array, 0, staff_array_size - 1, staff_id);
    for(int i = 0; i < staff_array_size; i++){
        if(staff_array[i].staff_id == staff_id);
        {
            index = i;
        }
    }
    if(staff_array[index].staff_id == staff_id){
        if(staff_array[index].staff_password == staff_password)
        {
            current_logged_in = staff_array[index];
            return 1;
        }
    }else {
        return 0;
    }
}

bool login()
{
    int flag = 0;
    int staff_id;
    string staff_password;

    while(flag == 0)
    {
        system("CLS");
        display_separator();
        cout << " eXcel Tuition Centre ";
        display_separator();
        cout << endl;

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
            cout << "Invalid Login Credentials. Please try again.";
        }
        else {
            cout << "Login Successful" << endl;
            return true;
        }
    }
    return false;
}
