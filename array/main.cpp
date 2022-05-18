#include "functions.hpp"
#include "display.hpp"
#include <iostream>

int main(){
    int choice;
    display_separator();
    cout << " eXcel Tuition Centre ";
    display_separator();
    cout << endl;
    cout << "1. Add new tutor" << endl;
    cout << "2. Display all tutors" << endl;
    cout << "3. Search tutor" << endl;
    cout << "4. Sort tutor" << endl;
    cout << "5. Modify tutor" << endl;
    cout << "6. Delete tutor" << endl;
    cout << "7. Report" << endl;
    cout << "8. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 8) {
        cout << "Good bye";
        return 0;
    }
    else if (choice == 1) add_new_tutor();
    else if (choice == 2) display();
    else if (choice == 3) search();
    else if (choice == 4) sort();
    else if (choice == 5) modify();
    else if (choice == 6) delete_tutor();
    else if (choice == 7) report();
    else cout << "Invalid input";

    return 0;
}

