#include <iostream>
using namespace std;

void modifiedBubbleSort(int* arr, int n) {
	cout << ".......Sorting by Modified Bubble Sort.......";
	int swapCount = 0, cmpCount = 0;
	
	for(int i=0; i<n-1; i++) {
		bool isSwap = false;
		
		for(int j=0; j<n-1 - i; j++) {
			
			cmpCount++;
			if(arr[j] > arr[j+1]) {
				// Swapping arr[j] & arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				isSwap = true;
				swapCount++;
			}
		}
		
		if(!isSwap) {
			cout << "\nCompares: " << cmpCount;
			cout << "\nSwaps: " << swapCount;
			return;
		}
		
		
	}
	
	cout << "\nCompares: " << cmpCount;
	cout << "\nSwaps: " << swapCount;
}

void bubbleSort(int* arr, int n) {
	int swapCount = 0, cmpCount = 0;
	cout << ".......Sorting by Standard Bubble Sort.......";
	
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-1 - i; j++) {
			
			cmpCount++;
			if(arr[j] > arr[j+1]) {
				// Swapping arr[j] & arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				swapCount++;
			}
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
	

	int arr1[] = {8, 4, 12, 15, 9, 20, 18, 22, 7, 30, 25, 32, 35, 32, 40, 2, 45, 56, 76};
	int arr_size = sizeof(arr1)/sizeof(int);
	
	display_array(arr1, arr_size);
	
	// Using Standard Bubble Sort
	cout << endl;
	bubbleSort(arr1, arr_size);
	display_array(arr1, arr_size);
	
	int arr2[] = {8, 4, 12, 15, 9, 20, 18, 22, 7, 30, 25, 32, 35, 32, 40, 2, 45, 56, 76};
	
	
	// Using Modified Bubble Sort
	cout << endl;
	modifiedBubbleSort(arr2, arr_size);
	display_array(arr2, arr_size);

	return 0;
}
