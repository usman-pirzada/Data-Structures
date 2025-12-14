#include <iostream>
using namespace std;

int findPivot(int* arr, int start, int end) {

    int mid = start + (end - start)/2;
    
    int first = arr[start];
    int middle = arr[mid];
    int last = arr[end];
    
    // Find median of three values
    if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
        return mid;
    else if ((middle <= first && first <= last) || (last <= first && first <= middle))
        return start;
    else
        return end;
}

int partition(int* arr, int start, int end) {
    int pivotIdx = findPivot(arr, start, end);
    int pivotValue = arr[pivotIdx];

    // Swapping arr[end] & arr[pivotIdx]
    int temp = arr[end];
    arr[end] = arr[pivotIdx];
    arr[pivotIdx] = temp;

    int pos = start;

    for(int i = start+1; i < end; i++) {
        if(arr[i] <= pivotValue && i != pos) {
            // Swapping arr[i] & arr[pos]
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;

            pos++;
        }
    }

    // Swapping arr[pos] & arr[end] to place pivotElement at pos where elements before pos are < pivotElement
    temp = arr[pos];
    arr[pos] = arr[end];
    arr[end] = temp;

    return pos;
}

void quickSort(int* arr, int start, int end) {
    if(start >= end) {
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
