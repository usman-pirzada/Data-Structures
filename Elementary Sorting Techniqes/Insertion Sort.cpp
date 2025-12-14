#include <iostream>
using namespace std;

void insertionSort(int* arr, int n) {
	cout << ".......Sorting by Insertion Sort.......";
	int shiftsCount = 0, cmpCount = 0;
	
	for (int i = 1; i < n; i++) {
		int curr = arr[i];
		int prev = i-1;

		/*
		while(prev >= 0 && arr[prev] > curr) {
			arr[prev+1] = arr[prev];
			prev--;
		}
		*/

		// The code style changed slightly to implement counters properly
		while (prev >= 0) {
            cmpCount++;
            if (arr[prev] > curr) {
                arr[prev + 1] = arr[prev];
                shiftsCount++;
                prev--;
            } else {
                break;
            }
        }

		arr[prev+1] = curr;
	}

	cout << "\nCompares: " << cmpCount;
	cout << "\nShifts: " << shiftsCount;
}

void display_array(int* arr, int n) {
	cout << "\n";
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {

	int arr[] = {8, 4, 12, 15, 9, 20, 18, 22, 7, 30, 25, 32, 35, 32, 40, 2, 45, 56, 76};
	int arr_size = sizeof(arr)/sizeof(int);

	display_array(arr, arr_size);

	// Using insertion sort
	insertionSort(arr, arr_size);

	display_array(arr, arr_size);

	return 0;
}
