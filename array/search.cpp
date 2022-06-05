#include "data.hpp"
#include "sort.hpp"
#include "display.hpp"
#include <iostream>
#include <limits>
using namespace std;

extern struct Tutor* clone_array;
extern struct Tutor* tutor_array;
extern int tutor_array_size;
sort_by type;

//binary search
int search_by_tutor_id(Tutor* input_array, int low, int high, int id){
    if (low <= high) {
        int middle = (low + high)/2;
        //if found
        if (input_array[middle].tutor_ID == id) return middle;
        //if id is lower, call recursive function and search lower
        else if (id < input_array[middle].tutor_ID) return search_by_tutor_id(input_array, low, middle - 1, id);
        //if id is higher, call recursive function and search higher
        else return search_by_tutor_id(input_array, middle + 1, high, id);
    }
    else {
        return -1;
    }
}

int search_by_tutor_rating(Tutor* input_array, int low, int high, int rating){
    int index = -1;
    while (low <= high){
        int middle = (low + high) / 2;
        //if found
        if (input_array[middle].rating == rating){
            index = middle;
            break;
        }
        //if id is higher, call recursive function and search higher
        else if (rating < input_array[middle].rating){
            high = middle - 1;
        }
        //if id is lower, call recursive function and search lower
        else {
            low = middle + 1;
        }
    }
    return index;
}

//print while rating is the same
void print_tutor_by_rating(Tutor* input_array, int rating, int index){
    while (input_array[index].rating == rating){
        display_detailed(input_array, index);
        index++;
    }
}

//validate choice
void validate_number() {
    while (cin.fail()) {
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//search menu
void search(){
    int choice;
    
    do {
        display_separator();
        cout << "Search Tutor";
        display_separator();
        cout << endl;
        cout << "1. Search tutor by tutor ID" << endl;
        cout << "2. Search tutor by rating" << endl;
        cout << "0. Return to main menu" << endl;
        cin >> choice;
        
        //copy array
        for(int i = 0; i < tutor_array_size; i++){
            clone_array[i] = tutor_array[i];
        }

        //search by tutor ID
        if (choice == 1) {
            int id;
            do {
                //sort by id
                quick_sort(clone_array, 0, tutor_array_size - 1, ID);
                cout << "Input tutor ID to be searched: ";
                cin >> id;
                validate_number();

                //binary search
                int index = search_by_tutor_id(clone_array, 0, tutor_array_size - 1, id);
                if (index == -1) {
                    cout << "Tutor is not registered in the database.";
                } 
                else {
                    display_detailed(tutor_array, index);
                }

                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
                validate_number();
            } while (choice == 1);
        }
        //search by tutor rating
        else if (choice == 2) {
            int rating;
            do {
                //sort by rating
                count_sort(clone_array, tutor_array_size);
                cout << "Input tutor rating to be searched: ";
                cin >> rating;
                validate_number();
                
                //binary search
                int index = search_by_tutor_rating(clone_array, 0, tutor_array_size - 1, rating);
                if (index == -1) {
                    cout << "Tutor with rating " << rating << " is not found.";
                } 
                else {
                    print_tutor_by_rating(clone_array, rating, index);
                }

                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
                validate_number();
            } while (choice == 1);
        }
        else if (choice != 0) {
            cout << "Invalid input" << endl;
        }
    } while(choice <= 0 && choice >= 2);
}

