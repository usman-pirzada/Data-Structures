// Comb Sort is a variant of Bubble Sort

#include <iostream>
using namespace std;

void combSort(int* arr, int n) {
    cout << ".......Sorting by Comb Sort.......";
    int gap = n;
	bool isSwap = true;

	while (gap > 1 || isSwap) {
		gap = gap/1.3;
		if(gap < 1) gap = 1;

		isSwap = false;
		for (int i = 0; i+gap < n; i++) {	// (i+gap) should NOT exceed the size of array
			if(arr[i] > arr[i+gap]) {
				int temp = arr[i];
				arr[i] = arr[i+gap];
				arr[i+gap] = temp;

				isSwap = true;
			}
		}
	}
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

    combSort(arr, arr_size);
    display_array(arr, arr_size);
    
    return 0;
}
