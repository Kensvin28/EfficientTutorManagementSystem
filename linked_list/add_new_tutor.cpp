// #include <iostream>
// #include <limits>
// #include "data.hpp"
// #include "display.hpp"

// using namespace std;
// extern struct Tutor* head;
// extern struct Tutor* tail;

// Tutor* create_new_tutor_node(int tutor_ID, string name, int date_joined, int date_terminated, double hourly_rate, string phone, string address, int centre_code, string centre_name, int subject_code, string subject_name, int rating) {
//     Tutor* new_node = new Tutor;
//     new_node->tutor_ID = tutor_ID;
//     new_node->name = name;
//     new_node->centre_code = centre_code;
//     new_node->date_joined = date_joined;
//     new_node->date_terminated = date_terminated;
//     new_node->hourly_rate = hourly_rate;
//     new_node->phone = phone;
//     new_node->address = address;
//     new_node->centre_code = centre_code;
//     new_node->centre_name = centre_name;
//     new_node->subject_code = subject_code;
//     new_node->subject_name = subject_name;
//     new_node->rating = rating;
//     new_node->next = NULL;
//     new_node->prev = NULL;

//     return new_node;
// }

// void insert_to_linked_list(Tutor* newnode)
// {
//     if(head == NULL){
//         head = tail = newnode;
//     }else
//     {
//         if(newnode->tutor_ID < head->tutor_ID){
//             newnode->next = head;
//             head->prev = newnode;
//             head = newnode;
//         }
//         else{
//             if(newnode->tutor_ID > tail->tutor_ID){
//                 newnode->prev = tail;
//                 tail->next = newnode;
//                 tail = newnode;
//             }else{
//                 // Tutor* current = current->next;
//                 Tutor* current = head->next;
//                 do{
//                     if(newnode->tutor_ID < current->tutor_ID){
//                         newnode->next = current;
//                         newnode->prev = current->prev;
//                         current->prev->next = newnode;
//                         current->prev = newnode;
//                     }
//                     current = current->next;
//                 }while(current != NULL)
//             }
//         }
//         linked_list_size = linked_list_size + 1;
//     }
    

//     if(staff_id <= staff_tail->staff_id/2)
//     {
//         Staff* current_ptr = staff_head;
//         do{
//             if(current_ptr->staff_id == staff_id)
//             {
//                 if (current_ptr->staff_password == staff_password)
//                 {
//                     return 1;
//                 } else {
//                     cout << "Password not matching" << endl;
//                 }
//             }
//             current_ptr = current_ptr->next;
//         }while(current_ptr != NULL);
//     }
//     else {
//         Staff* current_ptr = staff_tail;
//         do{
//             if(current_ptr->staff_id == staff_id)
//             {
//                 if (current_ptr->staff_password == staff_password)
//                 {
//                     return 1;
//                 }
//                 else {
//                     cout << "Password not matching" << endl;
//                 }
//             }
//             current_ptr = current_ptr->prev;
//         }while(current_ptr != NULL);
//     }

// }

// void add_new_tutor(){
//     int tutor_ID, date_joined, date_terminated, centre_code, subject_code, rating;
// 	string name, phone, address, centre_name, subject_name;
// 	double hourly_rate;

//     int choice;
//     do{
//         cout << "Add A new Tutor Record" << endl;
//         cout << "ID: ";
//         cin >> tutor_ID;

//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         cout << "\nName: ";
//         getline(cin,name);

//         cout << "\nDate Joined: ";
//         cin >> date_joined;

//         cout << "\nDate Terminated: ";
//         cin >> date_terminated;

//         cout << "\nHourly Rate: RM";
//         cin >> hourly_rate;

//         cout << "\nPhone: ";
//         cin >> phone;

//         cout << "\nAddress: ";
//         cin >> address;

//         cout << "\nCentre Code: ";
//         cin >> centre_code;

//         cout << "\nSubject Code: ";
//         cin >> subject_code;

//         cout << "\nSubject Name: ";
//         cin >> subject_name;

//         cout << "\nRating: ";
//         cin >> rating;

//         Tutor* new_node = create_new_tutor_node(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
//         insert_to_linked_list(new_node);

//     }while(choice != 1);
// }