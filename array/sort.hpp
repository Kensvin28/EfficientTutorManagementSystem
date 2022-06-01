#ifndef SORT_H
#define SORT_H

enum sort_by {
	ID,
	PAY_RATE
};
void quick_sort(Tutor*, int, int, sort_by);
void count_sort(Tutor*, int);

#endif