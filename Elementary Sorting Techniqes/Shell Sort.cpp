// Shell Sort is an improved version of Insertion Sort

#include <iostream>
using namespace std;

void shellSort(int* arr, int n) {
    cout << ".......Shell Sort.......";
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

	// Using shell sort
	shellSort(arr, arr_size);

	display_array(arr, arr_size);
    
    return 0;
}
