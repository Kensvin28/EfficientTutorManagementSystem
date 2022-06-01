#include <iostream>
#include <limits>
#include "data.hpp"
#include "display.hpp"

using namespace std;
extern struct Tutor* head;
extern struct Tutor* tail;

void modify_phone(Tutor* current){
    string phone;
    cout << "Insert new phone number: ";
    cin >> phone;
    current->phone = phone;
}

void modify_address(Tutor* current)
{
    string address;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insert new address: ";
    getline(cin,address);
    current->address = address;
}

void modify_tutor(int tutor_ID)
{
    if(head == NULL){
        return;
    }
    Tutor* current;
    if(tutor_ID <= tail->tutor_ID/2){
        current = head;
        do{
            if(current->tutor_ID == tutor_ID){
                system("cls");
                cin.clear();
                display_separator();
                cout << "Modify Tutor";
                display_separator();
                cout << endl;
                int choice = 1;
                do{
                    cout << "Record found:";
                    display_detailed_current(current);
                    cout << "0. Return" << endl;
                    cout << "1. Modify Phone" << endl;
                    cout << "2. Modify Address" << endl;
                    cout << "3. Modify Phone & Address" << endl;
                    cout << "Choice: ";
                    cin >> choice;
                    if(choice == 0) return;
                    else if(choice == 1) modify_phone(current);
                    else if (choice == 2) modify_address(current);
                    else if (choice == 3) {
                        modify_phone(current);
                        modify_address(current);
                    }else {
                        cout << "Invalid input";
                    }
                }while(choice >= 0 && choice < 4);
            }
            current = current->next;
            cout << endl;
        }while (current != NULL);
        cout << "Record not found";
    }else{
        current = tail;
        do{
            if(current->tutor_ID == tutor_ID){
                system("cls");
                cin.clear();
                display_separator();
                cout << "Modify Tutor";
                display_separator();
                cout << endl;
                int choice = 1;
                do
                {
                    cout << "Record found:";
                    display_detailed_current(current);
                    cout << "0. Return" << endl;
                    cout << "1. Modify Phone" << endl;
                    cout << "2. Modify Address" << endl;
                    cout << "3. Modify Phone & Address" << endl;
                    cout << "Choice: ";
                    cin >> choice;
                    if(choice == 0) return;
                    else if(choice == 1) modify_phone(current);
                    else if (choice == 2) modify_address(current);
                    else if (choice == 3) {
                        modify_phone(current);
                        modify_address(current);
                    }else{
                        cout << "Invalid input";
                    }
                }while(choice >= 0 && choice < 4);
            }
            current = current->prev;
            cout << endl;
        }while(current != NULL);
        cout << "Record not found" << endl;
    }
}

void modify()
{
    int choice = 0, tutor_ID;
    do{
        cout << "\nInput the tutor ID of a tutor record to modify: ";
        cin >> tutor_ID;
        modify_tutor(tutor_ID);
        // cout << "Type 1 to modify another record or any other key to return: ";
        // cin >> choice;
    } while(choice != 1);
    return;
}