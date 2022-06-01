#include "data.hpp"
#include "display.hpp"
#include "array.hpp"
#include <iostream>
using namespace std;
//dummy
extern struct Tutor* clone_array;
extern struct Tutor* tutor_array;
const string ID = "ID";
const string PAY_RATE = "PAY_RATE";

void swap(Tutor* input_array, int index1, int index2) {
	Tutor temp = input_array[index1];
	input_array[index1] = input_array[index2];
	input_array[index2] = temp;
}

int median_of_three(Tutor* input_array, int low_index, int high_index, string type){
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

void partition(Tutor* input_array, int left_index, int right_index, int pivot, string type){
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
		while (left_index < right_index && left < pivot){
			++left_index;
		}
		while (left_index < right_index && right > pivot){
			--right_index;
		}
		if (left_index >= right_index){
			return;
		}

		swap(input_array, left_index++, right_index--);
	}
}

void quick_sort(Tutor* input_array, int low_index, int high_index, string type) {
	if (high_index > low_index) {
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

		partition(input_array, left_position, right_position, pivot_position, type);

		if (left > pivot) {
			swap(input_array, left_position, pivot_position);
		}
		if (low_index < left_position) {
			quick_sort(input_array, low_index, high_index - 1, type);
		}
		if (high_index < left_position) {
			quick_sort(input_array, low_index, high_index - 1, type);
		}
	}
}

int get_max(Tutor* input_array, int size){
	int max = input_array[1].rating;
	for(int i = 2; i <= size; i++){
		if(input_array[i].rating > max){
			max = input_array[i].rating;
		}
	}
	return max;
}

void count_sort(Tutor* input_array, int size){
	int max = get_max(input_array, size);
	int* count_array = new int[max + 1];
	Tutor* output_array = new Tutor[size + 1];

	//count the frequency for each rating level
	for(int i = 1; i <= size; i++){
		count_array[input_array[i].rating]++;
	}

	//find cumulative frequency for each rating level
	for(int i = 1; i <= max; i++){
		count_array[i] = count_array[i] + count_array[i-1];
	}

	for(int i = size; i >= 1; i--){
		//fill sorted output array
		output_array[count_array[input_array[i].rating]] = input_array[i];
		//reduce counter
		count_array[input_array[i].rating]--;
	}

	//copy back to original array
	for(int i = 1; i <= size; i++){
		input_array[i] = output_array[i];
	}

	delete[] count_array;
	delete[] output_array;
}

//can be combined into the display section
void display_sorted(Tutor* input_array){

}

void sort() {
	int choice;
	//Get tutor array size
	int array_size = get_tutor_array_size();
	do {
		display_separator();
		cout << "Sort and Display Tutors";
		display_separator();
		cout << endl;
		cout << "1. Sort by ID";
		cout << "2. Sort by Hourly Rate";
		cout << "3. Sort by Rating";
		cout << "0. Return";
		cin >> choice;

		 //copy array
        for(int i = 0; i < array_size; i++){
            clone_array[i] = tutor_array[i];
        }
		if (choice == 1) {
			quick_sort(clone_array, 0, array_size - 1, "ID");
			display_sorted(clone_array);
		}
		else if (choice == 2) {
			quick_sort(clone_array, 0, array_size - 1, "PAY_RATE");
			display_sorted(clone_array);
		}
		else if (choice == 3) {
			count_sort(clone_array, array_size - 1);
			display_sorted(clone_array);
		}
		else if (choice != 0) {
			cout << "Invalid input!";
			choice = 0;
		}
	} while (choice <= 0 && choice >= 3);
}