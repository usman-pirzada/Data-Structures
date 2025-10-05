#include <iostream>
using namespace std;

void selectionSort(int* arr, int n) {
	cout << ".......Sorting by Selection Sort.......";
	int swapCount = 0, cmpCount = 0;

	for (int i = 0; i < n-1; i++) {
		int minIndex = i;

		for (int j = i+1; j < n; j++) {
			cmpCount++;
			if(arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
			swapCount++;
		}
	}

	
	cout << "\nCompares: " << cmpCount;
	cout << "\nSwaps: " << swapCount;
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

	// Using selection sort
	selectionSort(arr, arr_size);

	display_array(arr, arr_size);

	return 0;
}
