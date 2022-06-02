 #include <iostream>
 #include <limits>
 #include "data.hpp"
 #include "display.hpp"
 #include "search.hpp"

 using namespace std;
 extern struct Tutor* head;
 extern struct Tutor* tail;
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
        Tutor*current=head;
        if (head->next != NULL) {
            head=head->next;
            head->prev=NULL;
        }
        else {
            head = head->next;
        }
        
        cout<<"Tutor record with the tutor ID: " << tutor_ID << " is deleted" << endl;
        delete(current);
        linked_list_size--;

    }
    else if (position == linked_list_size){
        Tutor*current=tail;
        tail=tail->prev;
        tail->next = NULL;

        cout<<"Tutor record with the tutor ID: " << tutor_ID << " is deleted" << endl;
        delete(current);
        linked_list_size--;
    }
    else if(position <= linked_list_size/2)
    {
        Tutor*current;
        int current_position;
        current= head->next;
        current_position =2;
        do{
            if (current_position == position)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                cout<<"Tutor record with the tutor ID: " << tutor_ID << " is deleted" << endl;
                linked_list_size = linked_list_size -1;

                return;
            }
            current=current->next;
            current_position = current_position +1;
        }while(current!=NULL);
    }
    else
    {
        Tutor*current;
        int current_position;
        current=tail->prev;
        current_position = linked_list_size -1;
        do{
            if(current_position == position)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                cout<<"Tutor record with the tutor ID: " << tutor_ID << " is deleted" << endl;

                delete(current);
                linked_list_size = linked_list_size -1;
                return;
            }
            current=current->prev;
            current_position=current_position -1;

        }while(current!=NULL);

    }
}

 void remove()
 {
     int tutor_ID;
     int choice;
     do{
        cout<<"Input the tutor ID that you want to delete: ";
        cin>>tutor_ID;
        delete_tutor(tutor_ID);

        cout<<"Input 1 to delete another tutor or press any other key to return to the main menu: ";
        cin>>choice;
     }while(choice==1);
 }