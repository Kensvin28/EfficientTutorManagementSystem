#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
#include <ctime>
#include "data.hpp"
#include "display.hpp"
#include "search.hpp"

using namespace std;
extern struct Tutor* tutor_array;
extern struct Tutor* clone_array;
extern struct Staff current_logged_in;
extern int tutor_array_size;

void shift(Tutor* input_array, int position) {
    for (int i = position; i < tutor_array_size - 1; ++i) {
        input_array[i] = input_array[i+1];
    }
    tutor_array_size--;
}

void delete_old_record(int index) {
    string temp;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int d = ltm->tm_mday;
    int m = ltm->tm_mon + 1;
    int y = ltm->tm_year + 1900;

    int term_day, term_month, term_year;
    string date_terminated = tutor_array[index].date_terminated;
    if (date_terminated != "") {
        temp = date_terminated.substr(0, 2);
        term_day = atoi(temp.c_str());
        temp = date_terminated.substr(3, 2);
        term_month = atoi(temp.c_str());
        temp = date_terminated.substr(6, 4);
        term_year = atoi(temp.c_str());
        if (m - term_month < 0) {
            y--;
            m += 12;
        }
        int duration = (y - term_year) * 12 + (m - term_month);
        if (duration >= 6) {
            shift(tutor_array, index);
        }
    }
}

void auto_delete() {
    for (int i = 0; i < tutor_array_size; i++) {
        delete_old_record(i);
    }
}

void delete_tutor(int tutor_ID) {
    int position;
    if (tutor_array_size != 0) {
        position = search_by_tutor_id(tutor_array, 0, tutor_array_size - 1, tutor_ID);
        if (position != -1){
            cout << "Tutor with ID " << tutor_array[position].tutor_ID << " is deleted" << endl;
        }
        shift(tutor_array, position);
    }
}

 void remove()
 {
     system("cls");
     display_separator();
     cout << "Search Tutor";
     display_separator();
     cout << endl;
     int tutor_ID;
     int choice;
     do{
        if(current_logged_in.staff_position == "HR Manager"){
            cout<<"Input the tutor ID that you want to delete: ";
            cin>>tutor_ID;
            delete_tutor(tutor_ID);
        }
        else {
            cout<<"Only HR Manager is allowed to delete!"<<endl;
        }
        cout<<"Input 1 to delete another tutor or press any other key to return to the main menu: ";
        cin>>choice;
        validate_number();
     }while(choice==1);
 }