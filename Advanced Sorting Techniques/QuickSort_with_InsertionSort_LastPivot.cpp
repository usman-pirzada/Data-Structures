#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int* arr, int start, int end) {
    for(int i = start + 1; i <= end; i++) {
        int prevIdx = i - 1;
        int curr = arr[i];

        while(prevIdx >= start && arr[prevIdx] > curr) {
            arr[prevIdx+1] = arr[prevIdx];
            prevIdx--;
        }
        arr[prevIdx + 1] = curr;
    }
}

int partition(int* arr, int start, int end) {
    int idx = start;
    int pivot = arr[end];

    for(int i = start; i < end; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[end], arr[idx]);

    return idx;
}

void quickSort(int* arr, int start, int end) {
    if(start >= end) {
        return;
    }

    if((end - start) <= 6) {
        insertionSort(arr, start, end);
        return;
    }

    int pivotIdx = partition(arr, start, end);

    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

int main() {
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
