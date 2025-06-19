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

void reverseArray(vector<int>&);
int linearSearch(vector<int>&, int);

int main() {
    
    // ** Vectors initialization **
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
    // ----------


    // *----*----*----*----*

    // ** Problem Solving (Vectors/Arrays) **

    // Each +ve number in the array has its -ve value except one number, print the number.
    vector<int> vec4 = {2, 45, 74, 32, -45, -32, -2, 61, -74};
    int ans = 0;
    for(int val : vec4) {
        ans += val;
    }
    cout << "The required number is \"" << ans << "\".\n\n";

    /**
     *              SINGLE NUMBER
     * Given a non-empty array of integers nums, every element appears twice except for one.
     * Find that single one.
     * You must implement a solution with a linear runtime complexity and use only constant extra space.
     * https://leetcode.com/problems/single-number
     */

    // We'll make the use of a bitwise operator. By using XOR (^), it is possible to cancel two same numbers.
    // 0^0 = 0, 1^1 = 0, 0^1 = 1  | => n^n = 0, n^0 = n
    vector<int> vec5 = {4,1,2,1,2};
    ans = 0;
    for(int val : vec5) {
        ans ^= val;
    }
    cout << "Answer: " << ans << endl;
    // -----------

    // Reverse elements in a vector
    vector<int> vec6 = {1, 3, 5, 7, 9};
    cout << "\nVector: {";
    for(int val : vec6) {
        cout << val << ", ";
    }
    cout << "\b\b}";
    reverseArray(vec6); // Reversing
    cout << "\nReversed Vector: {";
    for(int val : vec6) {
        cout << val << ", ";
    }
    cout << "\b\b}\n\n";
    // -----------

    // Perfrom linear searching on a vector
    vector<int> vec7 = {2, 4, 6, 8, 10};
    int foundIndex = linearSearch(vec7, 6);
    if(foundIndex != -1) {
        cout << "Target value found at index \"" << foundIndex << "\".\n\n";
    } else {
        cout << "Target value NOT found!!\n\n";
    }
    // -----------



    
    return 0;
}

// ** Reverse elements in a vector **
void reverseArray(vector<int>& vec) {
    int startIndex = 0, endIndex = vec.size()-1;

    while(startIndex < endIndex) {
        swap(vec[startIndex], vec[endIndex]);
        startIndex++;
        endIndex--;
    }
}

// Perfrom Linear Search on a vector
int linearSearch(vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if(vec[i] == target) {
            return i;
        }
    }

    return -1;
}
