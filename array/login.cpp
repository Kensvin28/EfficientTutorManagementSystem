#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "display.hpp"
#include "data.hpp"
extern struct Staff* staff_array;
extern int staff_array_size;

using namespace std;

void add_new_staff(int staff_id, string staff_name, int centre_code, string staff_position, string staff_password)
{
    staff_array[staff_array_size].staff_id = staff_id;
    staff_array[staff_array_size].staff_name = staff_name;
    staff_array[staff_array_size].centre_code = centre_code;
    staff_array[staff_array_size].staff_position = staff_position;
    staff_array[staff_array_size].staff_password = staff_password;
}