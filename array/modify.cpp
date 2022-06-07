#include <iostream>
#include <limits>
#include "data.hpp"
#include "display.hpp"
#include "search.hpp"

using namespace std;
extern struct Tutor* tutor_array;
extern int tutor_array_size;

void modify_phone(Tutor* tutor_array, int index){
    string phone;
    cout << "Insert new phone number: ";
    cin >> phone;
    tutor_array[index].phone = phone;
    cout << endl;
}

void modify_address(Tutor* tutor_array, int index){
    string address;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insert new address: ";
    getline(cin,address);
    tutor_array[index].address = address;
    cout << endl;
}

void modify(){
    int tutor_ID, choice = 0, index = -1;
    do{
        cout << "Input tutor ID of tutor to modify: ";
        cin >> tutor_ID;
        index = search_by_tutor_id(tutor_array, 0, tutor_array_size-1, tutor_ID);
        if(index == -1){
            cout << "Tutor is not registered in the database." << endl;
        }else{
            system("cls");
                cin.clear();
                display_separator();
                cout << "Modify Tutor";
                display_separator();
                cout << endl;
                int choice = 1;
                do{
                    cout << "Record found:";
                    display_detailed(tutor_array, index);
                    cout << "0. Return" << endl;
                    cout << "1. Modify Phone" << endl;
                    cout << "2. Modify Address" << endl;
                    cout << "3. Modify Phone & Address" << endl;
                    cout << "Choice: ";
                    cin >> choice;
                    if(choice == 0) return;
                    else if(choice == 1) modify_phone(tutor_array, index);
                    else if (choice == 2) modify_address(tutor_array, index);
                    else if (choice == 3) {
                        modify_phone(tutor_array, index);
                        modify_address(tutor_array, index);
                    }else {
                        cout << "Invalid input";
                    }
                }while(choice >= 0 && choice < 4);
            }
        cout << "Record not found";
    }while(choice == 1);
}