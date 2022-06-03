 #include <iostream>
 #include <limits>
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
        input_array[i] = input_array[++i];
    }
    tutor_array_size--;
}

void delete_tutor(int tutor_ID) {
    int position;
    if (tutor_array_size != 0) {
        position = search_by_tutor_id(tutor_array, 0, tutor_array_size - 1, tutor_ID);
        cout << "Tutor with ID " << tutor_array[position].tutor_ID << " is deleted" << endl;
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
     }while(choice==1);
 }