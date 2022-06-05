#include "data.hpp"
#include "display.hpp"
#include "sort.hpp"
#include <iostream>
using namespace std;
extern struct Tutor* clone_array;
extern struct Tutor* tutor_array;
extern int tutor_array_size;
sort_by sort_type;

void swap(Tutor* input_array, int index1, int index2) {
	Tutor temp = input_array[index1];
	input_array[index1] = input_array[index2];
	input_array[index2] = temp;
}

//find pivot
int median_of_three(Tutor* input_array, int low_index, int high_index, sort_by type){
	int middle_index = (low_index + high_index) / 2;
	double low, middle, high;
	if (type == ID) {
		low = input_array[low_index].tutor_ID;
		middle = input_array[middle_index].tutor_ID;
		high = input_array[high_index].tutor_ID;
	} 
	else if (type == PAY_RATE) {
		low = input_array[low_index].hourly_rate;
		middle = input_array[middle_index].hourly_rate;
		high = input_array[high_index].hourly_rate;
	}
	
	if(low > middle){
		swap(input_array, low_index, middle_index);
	}
	if(low > high){
		swap(input_array, low_index, high_index);
	}
	if(middle > high){
		swap(input_array, middle_index, high_index);
	}
	swap(input_array, middle_index, high_index);

	return high_index;
}

void partition(Tutor* input_array, int left_index, int right_index, int pivot, sort_by type){
	double left, right;
	if (type == ID) {
		left = input_array[left_index].tutor_ID;
		right = input_array[right_index].tutor_ID;
	}
	else if (type == PAY_RATE) {
		left = input_array[left_index].hourly_rate;
		right = input_array[right_index].hourly_rate;
	}

	while(true){
		//if left less than pivot, leave as it is, move to higher index
		while (left_index < right_index && left < pivot){
			++left_index;
		}
		//if right more than pivot, leave as it is, move to lower index
		while (left_index < right_index && right > pivot){
			--right_index;
		}
		//return if left and right at the same place
		if (left_index >= right_index){
			return;
		}
		//swap left and right
		swap(input_array, left_index++, right_index--);
	}
}

void quick_sort(Tutor* input_array, int low_index, int high_index, sort_by type) {
	if (high_index > low_index) {
		//get pivot position
		int pivot_position = median_of_three(input_array, low_index, high_index, type);
		int left_position = low_index;
		int right_position = high_index - 1;

		double left, pivot;
		if (type == ID) {
			left = input_array[left_position].tutor_ID;
			pivot = input_array[pivot_position].tutor_ID;
		}
		else if (type == PAY_RATE) {
			left = input_array[left_position].hourly_rate;
			pivot = input_array[pivot_position].hourly_rate;
		}

		//divide array
		partition(input_array, left_position, right_position, pivot_position, type);

		//swap pivot
		if (left > pivot) {
			swap(input_array, left_position, pivot_position);
		}
		if (low_index < left_position) {
			quick_sort(input_array, low_index, high_index - 1, type);
		}
		if (high_index > left_position) {
			quick_sort(input_array, low_index + 1, high_index, type);
		}
	}
}

//get maximum
int get_max(Tutor* input_array, int size){
	int max = input_array[0].rating;
	for(int i = 1; i <= size; i++){
		if(input_array[i].rating > max){
			max = input_array[i].rating;
		}
	}
	return max;
}

//count sort rating
void count_sort(Tutor* input_array, int size){
	int max = get_max(input_array, size);
	int* count_array{ new int[max+1] {} };
	Tutor* output_array = new Tutor[size + 1];

	//count the frequency for each rating level
	for(int i = 1; i <= size; i++){
		++count_array[input_array[i-1].rating];
	}

	//find cumulative frequency for each rating level
	for(int i = 1; i <= max; i++){
		count_array[i] += count_array[i-1];
	}

	for(int i = size; i >= 1; i--){
		//fill sorted output array
		output_array[count_array[input_array[i-1].rating]] = input_array[i-1];
		//reduce counter
		count_array[input_array[i-1].rating]--;
	}

	//copy back to original array
	for(int i = 0; i < size; i++){
		input_array[i] = output_array[i+1];
	}

	delete[] count_array;
	delete[] output_array;
}

void sort() {
	int choice;
	do {
		system("cls");
		display_separator();
		cout << "Sort and Display Tutors";
		display_separator();
		cout << endl;
		do {
			cout << "1. Sort by ID" << endl;
			cout << "2. Sort by Hourly Rate" << endl;
			cout << "3. Sort by Rating" << endl;
			cout << "0. Return" << endl;
			cout << "Choice: ";
			cin >> choice;
		} while (choice < 0 && choice > 3 || cin.fail());

		 //copy array
        for(int i = 0; i < tutor_array_size; i++){
            clone_array[i] = tutor_array[i];
        }
		if (choice == 1) {
			quick_sort(clone_array, 0, tutor_array_size - 1, ID);
			display_sorted(clone_array);
		}
		else if (choice == 2) {
			quick_sort(clone_array, 0, tutor_array_size - 1, PAY_RATE);
			display_sorted(clone_array);
		}
		else if (choice == 3) {
			count_sort(clone_array, tutor_array_size);
			display_sorted(clone_array);
		}
		else if (choice != 0) {
			cout << "Invalid input!";
			choice = 0;
		}
		cout << "Press enter to continue...";
		cin.get();
	} while (choice >= 0 && choice <= 3 && cin.get() != '\n');
}