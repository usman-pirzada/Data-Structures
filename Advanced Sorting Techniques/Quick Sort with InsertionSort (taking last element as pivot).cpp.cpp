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
    
    
    
    return 0;
}
