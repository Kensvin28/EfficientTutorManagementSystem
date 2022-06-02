#include <iostream>
#include <limits>
#include "data.hpp"
#include "display.hpp"
#include "sort.hpp"
#include "search.hpp"
using namespace std;

extern struct Tutor* tutor_array;
extern int array_size;

int get_tutor_array_size() {
	return array_size;
}

void create_new_tutor(int tutor_ID, string name, string date_joined, string date_terminated, double hourly_rate, string phone, string address, int centre_code, string centre_name, int subject_code, string subject_name, int rating){
	int tutor_array_size = get_tutor_array_size();
	tutor_array[tutor_array_size].tutor_ID = tutor_ID;
    tutor_array[tutor_array_size].name = name;
    tutor_array[tutor_array_size].date_joined = date_joined;
    tutor_array[tutor_array_size].date_terminated = date_terminated;
    tutor_array[tutor_array_size].hourly_rate = hourly_rate;
    tutor_array_size++;
}


bool check_id(int tutor_id){
    int tutor_array_size = get_tutor_array_size();
    quick_sort(tutor_array, 0, tutor_array_size - 1, ID);
    int index = search_by_tutor_id(tutor_array, 0, tutor_array_size-1, tutor_id);
    if(index == -1){
        //id can be used
        return 1;
    }else{
        //id cannot be used
        return 0;
    }
}

// bool check_date(string date_joined, string date_terminated)
// {
//     string temp;

//     temp = date_joined.substr(0,2);
//     int join_year = atoi(temp.c_str());
//     temp = date_joined.substr(5,2);
//     int join_month = atoi(temp.c_str());
//     temp = date_joined.substr(8,4);
//     int join_day = atoi(temp.c_str());

//     temp = date_terminated.substr(0,2);
//     int term_year = atoi(temp.c_str());
//     temp = date_terminated.substr(5,2);
//     int term_month = atoi(temp.c_str());
//     temp = date_terminated.substr(8,4);
//     int term_day = atoi(temp.c_str());

//     if(term_year >= join_year) 
//     {
//         if(term_month >= join_month)
//         {
//             if(term_day >= join_day)
//             {
//                 return 1;
//             }else{
//                 return 1;
//             }
//         }else{
//             //term month is less than join month, but valid because year is greater
//             return 1;
//         }
//     }
// 
    //Terminated year is lesser than Joined Year
//     return 0;
// }

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
            cout << endl << "Add A new Tutor Record" << endl;
            cout << "\nID: ";
            cin >> tutor_ID;
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

        cout << "Date Joined(dd/mm/yyyy): ";
        cin >> date_joined;

        cout << "Date Terminated(dd/mm/yyyy): ";
        cin >> date_terminated;

        // valid = check_date(date_joined, date_terminated);

        // while(valid == 0 || cin.fail()){
        //     cout << endl << "Terminated is less than Joined / Invalid Format" << endl << "Please Re-enter:" << endl;
        //     cout << "Date Joined(dd/mm/yyyy): ";
        //     cin >> date_joined;

        //     cout << "Date Terminated(dd/mm/yyyy): ";
        //     cin >> date_terminated;

        //     valid = check_date(date_joined, date_terminated);
        // }

        cout << "Hourly Rate: RM";
        cin >> hourly_rate;

        cout << "Phone: ";
        cin >> phone;

        cout << "Address: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, address);

        cout << "Centre Code: ";
        cin >> centre_code;

        cout << "Subject Code: ";
        cin >> subject_code;

        cout << "Subject Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, subject_name);

        cout << "Rating: ";
        cin >> rating;

        create_new_tutor(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
        cout << "Record added successfully!" << endl << endl;
        cout << "Enter 1 to add another one or any other key to return: ";
        cin >> choice;
     }while(choice == 1);
}