 #include <iostream>
 #include <limits>
 #include "data.hpp"
 #include "display.hpp"
 #include "search.hpp"

 using namespace std;
 extern struct Tutor* head;
 extern struct Tutor* tail;
 extern int linked_list_size;

 Tutor* create_new_tutor_node(int tutor_ID, string name, string date_joined, string date_terminated, double hourly_rate, string phone, string address, int centre_code, string centre_name, int subject_code, string subject_name, int rating) {
     Tutor* new_node = new Tutor;
     new_node->tutor_ID = tutor_ID;
     new_node->name = name;
     new_node->centre_code = centre_code;
     new_node->date_joined = date_joined;
     new_node->date_terminated = date_terminated;
     new_node->hourly_rate = hourly_rate;
     new_node->phone = phone;
     new_node->address = address;
     new_node->centre_code = centre_code;
     new_node->centre_name = centre_name;
     new_node->subject_code = subject_code;
     new_node->subject_name = subject_name;
     new_node->rating = rating;
     new_node->next = NULL;
     new_node->prev = NULL;

     return new_node;
 }

 void insert_to_linked_list(Tutor* newnode)
 {
     if (head == NULL) {
         head = tail = newnode;
     }
     else
     {
         if (newnode->tutor_ID < head->tutor_ID) {
             newnode->next = head;
             head->prev = newnode;
             head = newnode;
         }
         else {
             if (newnode->tutor_ID > tail->tutor_ID) {
                 newnode->prev = tail;
                 tail->next = newnode;
                 tail = newnode;
             }
             else {
                 // Tutor* current = current->next;
                 Tutor* current = head->next;
                 do {
                     if (newnode->tutor_ID < current->tutor_ID) {
                         newnode->next = current;
                         newnode->prev = current->prev;
                         current->prev->next = newnode;
                         current->prev = newnode;
                     }
                     current = current->next;
                 } while (current != NULL);
             }
         }
         linked_list_size++;
     }
 }

bool check_id(int tutor_id) {
    //if head points to null, list is empty
    if (head == NULL) {
        return 1;
    }
       
    //if tutor node is closer to head
    if (tutor_id <= tail->tutor_ID / 2) {
        Tutor* current = head;
        while (current != NULL) {
            //display search result if match is found
            if (current->tutor_ID == tutor_id) {
                cout << "ID is used" << endl;
                return 0;
            }
            //traverse linked list
            current = current->next;
        }
    }
    else {
        Tutor* current = tail;
        while (current != NULL) {
            //display search result if match is found
            if (current->tutor_ID == tutor_id) {
                cout << "ID is used" << endl;
                return 0;
            }
            //traverse linked list
            current = current->prev;
        }
        
    }
    //ID not found
    return 1;
}

//date joined and terminate valdiation
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

    if(term_year >= join_year) 
    {
        if(term_month >= join_month)
        {
            if(term_day > join_day)
            {
                return 1;
            }
        }
    }

    //Terminated year is lesser than Joined Year
    return 0;
}

void add_new_tutor(){
    int tutor_ID, centre_code, subject_code, rating;
 	string name, date_joined, date_terminated,phone, address, centre_name, subject_name;
 	double hourly_rate;
    
    int valid = 0;
    int choice = 0;
    do{
        while(valid == 0){
            system("cls");
            display_separator();
            cout << endl << "Add a new tutor record" << endl;
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

        cout << "Date Joined(dd/mm/yyyy): ";
        cin >> date_joined;

        string temp;

        temp = date_joined.substr(0,2);
        int join_year = atoi(temp.c_str());
        temp = date_joined.substr(3,2);
        int join_month = atoi(temp.c_str());
        temp = date_joined.substr(6,4);
        int join_day = atoi(temp.c_str());

        cout << "Date Terminated(dd/mm/yyyy): ";
        cin >> date_terminated;

        //date joined & terminate validation
        while(valid == 0 || cin.fail()){
            cout << endl << "Terminated is less than Joined / Invalid Format" << endl << "Please Re-enter:" << endl;
            cout << "Date Joined(dd/mm/yyyy): ";
            cin >> date_joined;

            cout << "Date Terminated(dd/mm/yyyy): ";
            cin >> date_terminated;

            valid = check_date(date_joined, date_terminated);
        }

        cout << "Hourly Rate: RM";
        cin >> hourly_rate;
        validate_number();

        cout << "Phone: ";
        cin >> phone;

        cout << "Address: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, address);

        cout << "Centre Code: ";
        cin >> centre_code;
        validate_number();

        cout << "Centre Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, centre_name);

        cout << "Subject Code: ";
        cin >> subject_code;
        validate_number();

        cout << "Subject Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, subject_name);

        cout << "Rating: ";
        cin >> rating;
        validate_number();

        //validate integer values
        if(tutor_ID == 0 || hourly_rate == 0 || centre_code == 0 || subject_code == 0 || rating == 0) {
            cout << "Failed to add record!" << endl << endl;
        }
        else {
            Tutor* new_node = create_new_tutor_node(tutor_ID, name, date_joined, date_terminated, hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
            insert_to_linked_list(new_node);
            cout << "Record added successfully!" << endl << endl;
        }
        
        cout << "Enter 1 to add another one or any other key to return: ";
        cin >> choice;
     }while(choice == 1);
 }