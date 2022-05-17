#include <string.hpp>
struct Tutor
{
	int tutor_ID;
	string name;
	int date_joined;
	int date_terminated;
	double hourly_rate;
	string phone;
	string address;
	int centre_code;
	string centre_name;
	int subject_code;
	string subject_name;
	int rating;
	Tutor* next;
	Tutor* prev;
}*head,*tail;

struct Staff
{
	int staff_id;
	string staff_name;
	string staff_position;
	int centre_code;
	string staff_password;
	Staff* next;
	Staff* prev;
}*head, *tail;

