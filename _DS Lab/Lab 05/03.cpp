#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void modifiedBubbleSort(int* arr, int n) {

    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSwap = true;
            }
        }

        if(!isSwap) return;
    }
}

void combSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        
    }
}

void selectionSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        
    }
}

void insertionSort(int* arr, int n) {

}

void display_array(int* arr, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int arr[] = {6, 4, 8, 2, 9, 65, 45, 73, 22, 43, 98, 29, 54, 14, 51, 66, 7, 81, 33, 44};
    int arr_size = sizeof(arr)/sizeof(int);
    
    return 0;
}
