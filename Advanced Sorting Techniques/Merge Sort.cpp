#include <iostream>
using namespace std;

void merge(int* arr, int start, int mid, int end) {
    int i = start, j = mid+1, index = 0;
    int* temp = new int[(end-start)+1];

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[index] = arr[i];
            i++;
        } else {
            temp[index] = arr[j];
            j++;
        }

        index++;
    }

    while(i <= mid) {
        temp[index] = arr[i];
        index++;
        i++;
    }

    while(j <= end) {
        temp[index] = arr[j];
        index++;
        j++;
    }

    for (int k = 0; k < index; k++) {
        arr[start + k] = temp[k];
    }

    delete[] temp;
}

void mergeSort(int* arr, int start, int end) {
    if(start >= end) {
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
