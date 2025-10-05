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

int binary_search(int* arr, int n, int key) {

    bubbleSort(arr, n);

    int low = 0, high = n - 1;

    while(mid >= 0) {
        int mid = low + (high - low)/2;

        if(mid == key) {
            return i;
        } else if(mid > key) {
            high = high - mid;
        } else {
            low = mid - low;
        }
    }

    return -1;
}

void display_array(int* arr, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    
    
    return 0;
}
