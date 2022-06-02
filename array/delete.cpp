 #include <iostream>
 #include <limits>
 #include "data.hpp"
 #include "display.hpp"

 using namespace std;
extern struct Tutor* tutor_array;
extern struct Tutor* clone_array;
extern struct Staff current_logged_in;
extern int linked_list_size;


void delete_tutor(int tutor_ID){
    
}

 void remove()
 {
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