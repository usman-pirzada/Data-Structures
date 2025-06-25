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
