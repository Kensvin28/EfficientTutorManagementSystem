#include <iostream>
#include <ctime>
#include "data.hpp"
#include "display.hpp"
#pragma warning(disable:4996)
extern struct Tutor* tutor_array;
extern struct Tutor* clone_array;
extern int tutor_array_size;

using namespace std;

int day_of_week(int y, int m, int d)
{
   static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   y -= m < 3;
   return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

//function to print report
void generate_report() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int d = ltm->tm_mday;
    int m = ltm->tm_mon + 1;
    int y = ltm->tm_year + 1900;
    
    int day_calc = day_of_week(y, m, d);
    int array_size = tutor_array_size - 1;
    //0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday
    if (day_calc == 0) 
    {
        cout << "Today is Sunday, Printing Report...";
        for(int i = 0; i < array_size; i++)
        {
            display_detailed(tutor_array, i);
        }

    }else{
        cout << "No report available for this week yet" << endl;
    }

    return;
}

//report menu
void report()
{
    generate_report();
    system("pause");

    return;
}