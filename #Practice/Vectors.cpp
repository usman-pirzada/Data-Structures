/**
 * Below data structures are known as STL (Standard Template Library) Containers:
 *  > Vector
 *  > Queue
 *  > Stack
 *  > Set
 * 
 * Vector Syntax:
 *      vector<int> vec; // current size: 0
 *      vector<int> vec = {1, 2, 3};
 *      vector<int> vec(3, 0);
 */

#include <iostream>
#include <vector>
using namespace std;

// ** Reverse elements in a vector **
void reverseArray(vector<int>& vec) {
    int startIndex = 0, endIndex = vec.size()-1;

    while(startIndex < endIndex) {
        swap(vec[startIndex], vec[endIndex]);
        startIndex++;
        endIndex--;
    }
}

int main() {
    
    // Vectors initialization
    vector<int> vec1;
    cout << vec1.size() << "\n\n";

    vector<int> vec2 = {2, 4, 6};
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << endl;
    }
    cout << endl;

    vector<char> vec3(4 /*size*/, 'a' /*initialization to all indexes*/);
    for(char ch : vec3) {
        cout << ch << endl;
    }
    cout << endl;
    // -----------

    vector<int> vec4 = {1, 3, 5, 7, 9};

    // Print original vector
    cout << "\nVector: {";
    for(int val : vec4) {
        cout << val << ", ";
    }
    cout << "\b\b}";

    reverseArray(vec4); // Calling function to reverse elements

    // Print reversed array
    cout << "\nReversed Vector: {";
    for(int val : vec4) {
        cout << val << ", ";
    }
    cout << "\b\b}\n\n";
 
    return 0;
}
