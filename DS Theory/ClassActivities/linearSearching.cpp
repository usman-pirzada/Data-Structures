#include <iostream>
using namespace std;

int linearSearch(const int arr[], int arr_size, int target) {
    if(arr_size <= 0) {
        cout << "Invalid Array size!!";
    }

    for (int i = 0; i < arr_size; i++) {
        if(arr[i] == target) return i;
    }

    return -1;
}

int main() {
    
    int arr[] = {56, 84, 24, 61, 73};
    int arr_size = sizeof(arr)/sizeof(int);
    
    cout << linearSearch(arr, arr_size, 24) << endl;
    cout << linearSearch(arr, arr_size, 65);
    
    return 0;
}
