#include <iostream>
#include <limits>
#include "data.hpp"
#include "display.hpp"
#include "sort.hpp"
#include "search.hpp"
using namespace std;

extern struct Tutor* tutor_array;
extern int tutor_array_size;

void create_new_tutor(int tutor_ID, string name, string date_joined, string date_terminated, double hourly_rate, string phone, string address, int centre_code, string centre_name, int subject_code, string subject_name, int rating){
	tutor_array[tutor_array_size].tutor_ID = tutor_ID;
    tutor_array[tutor_array_size].name = name;
    tutor_array[tutor_array_size].date_joined = date_joined;
    tutor_array[tutor_array_size].date_terminated = date_terminated;
    tutor_array[tutor_array_size].hourly_rate = hourly_rate;
    tutor_array[tutor_array_size].phone = phone;
    tutor_array[tutor_array_size].address = address;
    tutor_array[tutor_array_size].centre_code = centre_code;
    tutor_array[tutor_array_size].centre_name = centre_name;
    tutor_array[tutor_array_size].subject_code = subject_code;
    tutor_array[tutor_array_size].subject_name = subject_name;
    tutor_array[tutor_array_size].rating = rating;
    tutor_array_size++;
}


bool check_id(int tutor_id){
    quick_sort(tutor_array, 0, tutor_array_size - 1, ID);
    int index = search_by_tutor_id(tutor_array, 0, tutor_array_size-1, tutor_id);
    if(index == -1){
        //id can be used
        cout << "ID is available" << endl;
        return 1;
    } else {
        //id cannot be used
        cout << "ID is used" << endl;
        return 0;
    }
}

bool check_date(string date_joined, string date_terminated)
{
    string temp;

    temp = date_joined.substr(0,2);
    int join_day = atoi(temp.c_str());
    temp = date_joined.substr(3,2);
    int join_month = atoi(temp.c_str());
    temp = date_joined.substr(6,4);
    int join_year = atoi(temp.c_str());

    temp = date_terminated.substr(0,2);
    int term_day = atoi(temp.c_str());
    temp = date_terminated.substr(3,2);
    int term_month = atoi(temp.c_str());
    temp = date_terminated.substr(6,4);
    int term_year = atoi(temp.c_str());

    if(term_year > join_year) 
    {
        return 1;
    } else {
        if(term_month > join_month)
        {
            return 1;
        } else{
             if(term_day > join_day)
            {
                return 1;
            }else if (term_day == join_day){
                return 0;
            }
        }
    }


    //Terminated year is lesser than Joined Year
    return 0;
}

void add_new_tutor() {
	int tutor_ID, centre_code, subject_code, rating;
 	string name, date_joined, date_terminated,phone, address, centre_name, subject_name;
 	double hourly_rate;
    
    int valid = 0;
    int choice = 0;
    do{
        while(valid == 0){
            system("cls");
            display_separator();
            cout << endl << "Add a new Tutor Record" << endl;
            cout << "\nID: ";
            cin >> tutor_ID;
            validate_number();
            valid = check_id(tutor_ID);
            if(valid == 0){
                int cont;
                cout << endl << "Type 0 to enter another ID or other to go back: ";
                cin >> cont;
                if(cont != 0 || cin.fail()){
                    return;
                }
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        getline(cin,name);

        do{
            cout << "Date Joined(dd/mm/yyyy): ";
            cin >> date_joined;

            cout << "Date Terminated(dd/mm/yyyy) (put - if still active): ";
            cin >> date_terminated;

            if (date_terminated == "-") {
                date_terminated = "";
            }
            else {
                valid = check_date(date_joined, date_terminated);
            }

            if(valid == 0){
                cout << "Terminated is less than Joined / Invalid Format" << endl << "Please Re-enter:" << endl << endl;
            }
        } while(valid == 0 || cin.fail());

        do {
            cin.clear();
            cout << "Hourly Rate(RM40-80): RM";
            cin >> hourly_rate;
            validate_number();
            if (hourly_rate < 40 || hourly_rate > 80) {
                cout << "Please enter valid hourly rate!" << endl << endl;
            }
        } while (hourly_rate < 40 || hourly_rate > 80);

        cout << "Phone: ";
        cin >> phone;

        cout << "Address: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, address);

        do {
            cin.clear();
            cout << "Enter Centre Code(1-5): ";
            cin >> centre_code;
            validate_number();
            if (centre_code < 1 || centre_code > 5) {
                cout << "Please enter valid centre code!" << endl << endl;
            }
        } while (centre_code < 1 || centre_code > 5);

        cout << "Centre Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, centre_name);

        cout << "Subject Code: ";
        cin >> subject_code;
        validate_number();

        cout << "Subject Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, subject_name);

        do{
            cout << "Rating(1-5): ";
            cin >> rating;
            validate_number();
            if(rating < 1 || rating > 5){
                cout << "Please enter valid rating!" << endl << endl;
            }
        }while(rating < 1 || rating > 5);

        //validate
        if(tutor_ID == 0 || hourly_rate == 0 || centre_code == 0 || subject_code == 0 || rating == 0) {
            cout << "Failed to add record!" << endl << endl;
        }
        else {
            create_new_tutor(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
            cout << "Record added successfully!" << endl << endl;
        }
        cout << "Enter 1 to add another one or any other key to return: ";
        cin >> choice;
     }while(choice == 1);
    //  return;
}