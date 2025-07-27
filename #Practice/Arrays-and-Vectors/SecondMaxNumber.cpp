/**
 *      "SECOND MAXIMUM NUMBER"
 * 
 * EXPLANATION:
 * Finds the index of the 2nd largest element in a vector by:
 *  1. Setting initial max and second max from first two elements
 *  2. Traversing the rest of the array and updating both values as needed
 *  3. Returning the index of the second largest number (-1 if vector has fewer than 2 elements)
 * 
 * Time Complexity: O(n) - single pass through the array
 * Space Complexity: O(1) - uses constant extra space
 */

#include <iostream>
#include <vector>
using namespace std;

int secondMax(vector<int>& vec) {
    if(vec.size() < 2) return -1;   // If there are less than two elements in the vector, the 2nd max num can't be found

    int max1_index, max2_index;
    if(vec[0] < vec[1]) {
        max2_index = 0;
        max1_index = 1;
    } else {
        max1_index = 0;
        max2_index = 1;
    }

    for (size_t i = 2; i < vec.size(); i++) {

        if(vec[max1_index] < vec[i]) {
            max2_index = max1_index;
            max1_index = i;
        } else if(vec[max2_index] < vec[i]) {
            max2_index = i;
        }
    }
    return max2_index;
}

int main() {
    
    vector<int> vec1 = {95};
    vector<int> vec2 = {26, 32};
    vector<int> vec3 = {25, 16, 38, 10, 35, 48, 20, 50};

    int foundIndex = secondMax(vec1);
    if(foundIndex != -1) {
        cout << "The 2nd largest number is \"" << vec1[foundIndex] << "\" found at index \'" << foundIndex << "\'.\n\n";
    } else {
        cout << "NO 2nd LARGEST ELEMENT FOUND, as array is empty or it has less than two elements.\n\n";
    }

    foundIndex = secondMax(vec2);
    if(foundIndex != -1) {
        cout << "The 2nd largest number is \"" << vec2[foundIndex] << "\" found at index \'" << foundIndex << "\'.\n\n";
    } else {
        cout << "NO 2nd LARGEST ELEMENT FOUND, as array is empty or it has less than two elements.\n\n";
    }

    foundIndex = secondMax(vec3);
    if(foundIndex != -1) {
        cout << "The 2nd largest number is \"" << vec3[foundIndex] << "\" found at index \'" << foundIndex << "\'.\n\n";
    } else {
        cout << "NO 2nd LARGEST ELEMENT FOUND, as array is empty or it has less than two elements.\n\n";
    }
    
    return 0;
}
