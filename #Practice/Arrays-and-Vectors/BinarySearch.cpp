/**
 *      "BINARY SEARCH"
 * 
 * EXPLANATION:
 * Binary search works by repeatedly dividing the search range in half:
 *  1. Compare target with middle element
 *  2. If target matches, return the index
 *  3. If target is smaller, search the left half
 *  4. If target is larger, search the right half
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * Note: Binary search requires the array to be sorted!
 */

#include <iostream>
using namespace std;

int binarySearch(int arr[], int arr_size, int target) {    // Valid for sorted arrays ONLY
    int foundIndex = -1;
    int start = 0, end = arr_size - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        // ```(end - start) / 2``` is half the distance b/w 'start' and 'end'   

        if(arr[mid] < target) {
            start = mid + 1;
        } else if(arr[mid] > target) {
            end = mid - 1;
        } else {
            foundIndex = mid;
            break;
        }
    }

    return foundIndex;
}

int main() {
    
    int arr[] = {3, 5, 6, 13, 22, 87, 110, 230};    // Sorted Array
    int arr_sz = sizeof(arr) / sizeof(arr[0]);

    int idx = binarySearch(arr, arr_sz, 87);
    cout << "Target value found at index \"" << idx << "\".";
    
    return 0;
}
