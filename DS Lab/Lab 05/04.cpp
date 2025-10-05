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

void display_array(int* arr, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int arr_size = sizeof(arr)/sizeof(int);

    display_array(arr, arr_size);

    bubbleSort(arr, arr_size);

    display_array(arr, arr_size);
    
    return 0;
}
