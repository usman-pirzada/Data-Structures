#include <iostream>
using namespace std;

// Binary Search requires array to be sorted
int binarySearch(int* arr, int n, int key) {
    int start = 0, end = n-1;
    int cmpCount = 0;

    while (start <= end) {
        int mid = start + (end - start)/2;
        
        cmpCount++;
        if(arr[mid] == key) {
            cout << "\nCompares: " << cmpCount;
            return mid;
        } else if(arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
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
    int arr[] = {2, 4, 7, 8, 9, 12, 15, 18, 20, 22, 25, 30, 32, 35, 40, 45, 56, 76};
    int arr_size = sizeof(arr)/sizeof(int);
    
    cout << "Array elements:";
    display_array(arr, arr_size);
    
    int key;
    cout << "\nEnter the element to search: ";
    cin >> key;
    
    cout << "\n.......Searching using Binary Search.......";
    int result = binarySearch(arr, arr_size, key);
    
    if(result != -1) {
        cout << "\nElement " << key << " found at index " << result;
    } else {
        cout << "\nElement " << key << " not found in the array";
    }
    
    cout << endl;
    
    return 0;
}
