#include <iostream>
#include <ctime>
#include "data.hpp"
#pragma warning(disable:4996)
extern struct Tutor* head;
extern struct Tutor* tail;

using namespace std;

//References: https://www.codespeedy.com/how-to-find-day-from-date-in-cpp/  
//https://www.softwaretestinghelp.com/date-and-time-in-cpp/  

int day_of_week(int y, int m, int d)
{
   static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   y -= m < 3;
   return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

void report() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int d = ltm->tm_mday;
    int m = ltm->tm_mon + 1;
    int y = ltm->tm_year + 1900;
    
    int day_calc = day_of_week(y, m, d);
    if (day_calc == 0) 
    {
        Tutor* current = head;
        do{
            cout << "Today is Sunday, printing report" << endl;
            cout << "| " << current->tutor_ID << "| " << current->name << "| " << current->date_joined << "| " + current->date_terminated << "| " << current->hourly_rate << "| " << current->phone << 
            "| " << current->address << "| " << current->centre_code << "| " << current->centre_name << "| " << current->subject_code << "| " << current->subject_name << "| " << current->rating << "| " << endl;
            current = current->next;
        }while(current != NULL);

    }else{
        cout << "No report available for this week yet";
    }

    return;
}