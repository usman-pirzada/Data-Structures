#include <iostream>
using namespace std;

void removeDuplicates(int* arr, int arr_size) {
    int newArr[arr_size];

    newArr[0] = arr[0];

    int x = 0;
    for (size_t i = 1; i < arr_size; i++) {
        if(newArr[x] != arr[i]) {
            x++;
            newArr[x] = arr[i];
        }
    }

    arr = newArr;
}

void removeDuplicates_Optimal(int* arr) {
    
}

int main() {
    
    int arr[] = {2, 2, 3, 6, 6, 6, 9, 9, 10};
    int arr_sz = sizeof(arr)/sizeof(int);

    removeDuplicates(arr, arr_sz);
    
    cout << "{";
    for (size_t i = 0; i < arr_sz; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\b\b}";
    
    return 0;
}
