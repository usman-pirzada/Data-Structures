#include <iostream>
using namespace std;

int linear_search(int* arr, int n, int key) {

    for (int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    
    int arr[] = {44, 63, 32, 2, 13, 5, 1, 0};
    int arr_size = sizeof(arr)/sizeof(int);

    cout << "\n '5' is found at index: " << linear_search(arr, arr_size, 5) << endl;
    
    return 0;
}
