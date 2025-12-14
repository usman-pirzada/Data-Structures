#include <iostream>
using namespace std;

int linearSearching(int* arr, int n, int key) {
    int cmpCount = 0;
    for (int i = 0; i < n; i++) {
        cmpCount++;
        if(arr[i] == key) {
            cout << "\nCompares: " << cmpCount;
            return i;
        }
    }

    cout << "\nCompares: " << cmpCount;
    return -1;
}

void display_array(int* arr, int n) {
    cout << "\n";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {8, 4, 12, 15, 9, 20, 18, 22, 7, 30, 25, 32, 35, 40, 2, 45, 56, 76};
    int arr_size = sizeof(arr)/sizeof(int);
    
    cout << "Array elements:";
    display_array(arr, arr_size);
    
    int key;
    cout << "\nEnter the element to search: ";
    cin >> key;
    
    cout << "\n.......Searching using Linear Search.......";
    int result = linearSearching(arr, arr_size, key);
    
    if(result != -1) {
        cout << "\nElement " << key << " found at index " << result;
    } else {
        cout << "\nElement " << key << " not found in the array";
    }
    
    cout << endl;
    
    return 0;
}
