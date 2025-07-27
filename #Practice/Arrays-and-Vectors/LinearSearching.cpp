/**
 *      "LINEAR SEARCH"
 * 
 * EXPLANATION:
 * Linear search works by sequentially checking each element of a collection:
 *  1. Start from the first element and compare with target
 *  2. If target matches, return the index
 *  3. If not, move to the next element
 *  4. Repeat until target is found or the end is reached
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Note: Linear search works for both sorted and unsorted collections!
 */

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& vec, int target) {    // Using Vectors
    for (int i = 0; i < vec.size(); i++) {
        if(vec.at(i) == target) return i;
    }

    return -1;
}

int linearSearch(int arr[], int arr_size, int target) {    // Using Arrays
    for (int i = 0; i < arr_size; i++) {
        if(arr[i] == target) return i;
    }
    
    return -1;
}

int main() {
    
    vector<int> vec = {53, 5, 61, 73, 9, 12};
    
    int arr[] = {31, 41, 4, 6, 1}, arr_size = sizeof(arr)/sizeof(int);


    int foundIndex = linearSearch(vec, 12 /*target*/);
    if(foundIndex != -1) {
        cout << "Target number found at index \"" << foundIndex << "\"." << endl;
    } else {
        cout << "Target element NOT found!!";
    }


    foundIndex = linearSearch(arr, arr_size, 41 /*target*/);
    if(foundIndex != -1) {
        cout << "Target number found at index \"" << foundIndex << "\"." << endl;
    } else {
        cout << "Target element NOT found!!";
    }
    
    
    return 0;
}
