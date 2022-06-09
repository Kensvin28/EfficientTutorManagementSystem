#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
 #include <limits>
 #include "data.hpp"
 #include "display.hpp"
 #include "search.hpp"

 using namespace std;
 extern struct Tutor* head;
 extern struct Tutor* tail;
 extern struct Staff* current_logged_in;
 extern int linked_list_size;

void delete_tutor(int tutor_ID)
{
    int position = search_by_tutor_id(tutor_ID);

    if (position == 0 || head == NULL)
    {
        return;
    }
    if (position == 1) 
    {
        Tutor* current=head;
        if (head->next != NULL) {
            head=head->next;
            head->prev=NULL;
        }
        else {
            head = head->next;
        }
        
        delete(current);
        linked_list_size--;

    }
    else if (position == linked_list_size){
        Tutor* current=tail;
        tail=tail->prev;
        tail->next = NULL;

        delete(current);
        linked_list_size--;
    }
    else if(position <= linked_list_size/2)
    {
        Tutor* current = head;
        int current_position;
        current= head->next;
        current_position =2;
        do{
            if (current_position == position)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                linked_list_size = linked_list_size -1;

                return;
            }
            current=current->next;
            current_position = current_position +1;
        }while(current!=NULL);
    }
    else
    {
        Tutor*current = tail;
        int current_position;
        current=tail->prev;
        current_position = linked_list_size -1;
        do{
            if(current_position == position)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                

                delete(current);
                linked_list_size = linked_list_size -1;
                return;
            }
            current=current->prev;
            current_position=current_position -1;

        }while(current!=NULL);

    }
}

void auto_delete() {
    string temp;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int d = ltm->tm_mday;
    int m = ltm->tm_mon + 1;
    int y = ltm->tm_year + 1900;

    int term_day, term_month, term_year;
    Tutor* current = head;
    //string date_terminated;
    while (current != NULL) {
        //date_terminated = current->date_terminated;
        if (current->date_terminated != "") {
            temp = current->date_terminated.substr(0, 2);
            term_day = atoi(temp.c_str());
            temp = current->date_terminated.substr(3, 2);
            term_month = atoi(temp.c_str());
            temp = current->date_terminated.substr(6, 4);
            term_year = atoi(temp.c_str());
            if (m - term_month < 0) {
                y--;
                m += 12;
            }
            int duration = (y - term_year) * 12 + (m - term_month);
            if (duration >= 6) {
                Tutor* temp = current;
                current = current->next;
                delete_tutor(temp->tutor_ID);
                continue;
            }
        }
        current = current->next;
    }
}

 void remove()
 {
     int tutor_ID;
     int choice;
     do{
        if(current_logged_in->staff_position == "HR Manager"){
            cout<<"Input the tutor ID that you want to delete: ";
            cin>>tutor_ID;
            delete_tutor(tutor_ID);
            cout << "Tutor record with the tutor ID: " << tutor_ID << " is deleted" << endl;
        }
        else {
            cout<<"Only HR Manager is allowed to delete!"<<endl;
        }
        cout<<"Input 1 to delete another tutor or press any other key to return to the main menu: ";
        cin>>choice;
     }while(choice==1);
 }