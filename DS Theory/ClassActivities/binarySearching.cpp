#include <iostream>
using namespace std;

int binarySearch(const int *arr, int arrSize, int target) {
    int start = 0, end = arrSize - 1;

    while(start <= end) {
        int mid = start + (end - start)/2;

        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    
    int arr[] = {64, 37, 81, 40, 99, 75, 57};
    int arr_size = sizeof(arr)/sizeof(int);

    cout << binarySearch(arr, arr_size, 75) << endl;
    cout << binarySearch(arr, arr_size, 43);
    
    return 0;
}
