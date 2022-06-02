#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

struct Tutor
{
	int tutor_ID;
	string name;
	string date_joined;
	string date_terminated;
	double hourly_rate;
	string phone;
	string address;
	int centre_code;
	string centre_name;
	int subject_code;
	string subject_name;
	int rating;
};

struct Staff
{
	int staff_id;
	string staff_name;
	string staff_position;
	int centre_code;
	string staff_password;
};

#endif