#include <iostream>
using namespace std;

void insertionSort(int* arr, int start, int end) {
    int arr_size = (end - start) + 1;
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

void merge(int* arr, int start, int mid, int end) {
    int i = start, j = mid+1, arr_size = (end-start)+1;
    int* temp = new int[arr_size];
    int tempIdx = 0;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[tempIdx] = arr[i];
            i++;
        } else {
            temp[tempIdx] = arr[j];
            j++;
        }

        tempIdx++;
    }

    while(i <= mid) {
        temp[tempIdx++] = arr[i++];
    }

    while(j <= end) {
        temp[tempIdx++] = arr[j++];
    }

    for (int k = 0; k < arr_size; k++) {
        arr[start + k] = temp[k];
    }

    delete[] temp;
}

void mergeSort(int* arr, int start, int end) {
    if(start >= end) {
        return;
    }

    if((end - start) <= 6) {
        insertionSort(arr, start, end);
        return;
    }

    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main() {
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
