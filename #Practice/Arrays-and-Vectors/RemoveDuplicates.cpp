/// TODO: Add functions for unsorted arrays too!

#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int arr_size, int resultArr[]) {    // Valid for sorted arrays
    if(arr_size == 0) return 0;

    resultArr[0] = arr[0];
    int resultArr_size = 1;

    for (int i = 1; i < arr_size; i++) {
        if(resultArr[resultArr_size - 1] != arr[i]) {
            resultArr[resultArr_size] = arr[i];
            resultArr_size++;
        }
    }

    return resultArr_size;
}

int removeDuplicates_inPlace(int* arr, int arr_size) {  // Valid for sorted arrays
    if(arr_size == 0) return 0;

    int x = 0;
    for (int i = 1; i < arr_size; i++) {
        if(arr[x] != arr[i]) {
            x++;
            arr[x] = arr[i];
        }
    }

    return (x+1);   // 'x' is the index of the last unique element, so '(x+1)' gives the total count of unique elements
}

int main() {
    
    int arr[] = {2, 2, 3, 6, 6, 6, 9, 9, 10};
    int arr_sz = sizeof(arr)/sizeof(int);

    int resultArr[arr_sz];
    int newArr_size = removeDuplicates(arr, arr_sz, resultArr);
    
    cout << "{";
    for (size_t i = 0; i < newArr_size; i++) {
        cout << resultArr[i] << ", ";
    }
    cout << "\b\b}" << endl;

    newArr_size = removeDuplicates_inPlace(arr, arr_sz);
    cout << "{";
    for (size_t i = 0; i < newArr_size; i++) {
        cout << resultArr[i] << ", ";
    }
    cout << "\b\b}";
    
    return 0;
}
