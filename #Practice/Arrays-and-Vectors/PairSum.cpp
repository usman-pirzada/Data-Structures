/**
 *      "PAIR SUM"
 * Given an array of integers, find a pair of elements that add up to a target sum.
 * Return the indices of these two elements.
 * 
 * SOLUTION:
 * Brute Force Approach [O(n²)]:
 *  This approach finds all possible pairs by:
 *      1. Using two nested loops to generate all possible pairs of elements
 *      2. Checking if their sum equals the target sum
 *      3. Returning the indices once a matching pair is found
 *  This approach works for both sorted and unsorted arrays.
 *
 * Two Pointer Approach [O(n)]:
 *  This optimized approach leverages a sorted array by:
 *      1. Starting with two pointers - one at the beginning and one at the end of the array
 *      2. Calculating the sum of elements at these pointers
 *      3. If sum = target: return the indices
 *      4. If sum < target: move LEFT pointer towards right (increasing the sum)
 *      5. If sum > target: move RIGHT pointer towards left (decreasing the sum)
 *  Note: This approach only works for sorted arrays.
 *
 * Space Complexity:
 *  - Both approaches use O(1) additional space (excluding the return vector)   // todo:
 *  - The return vector stores at most 2 indices
 */

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findTarget(vector<int>& vec, int targetSum) {   // Valid for Sorted/Unsorted Vectors

    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i+1; j < vec.size(); j++) {

            if(vec[i] + vec[j] == targetSum) {
                return {i, j};
            }
        }
    }
    
    return {-1, -1};
}

pair<int, int> findTarget_Optimal(vector<int>& vec, int targetSum) {   // Valid for Sorted Vectors ONLY

    int left = 0, right = vec.size() - 1;
    
    while(left < right) {
        int pairSum = vec[left] + vec[right];

        if(pairSum == targetSum) {
            return {left, right};
        } else if(pairSum < targetSum) {
            left++;
        } else {
            right--;
        }
    }

    return {-1, -1};
}

int main() {

    vector<int> vec0 = {61, 9, 7, 4, 24, 32, 1};    // Unsorted Vector
    pair<int, int> ans0 = findTarget(vec0, 10 /*target*/);
    if(ans0.first >= 0 && ans0.second >= 0) {
        cout << "\nAns: " << ans0.first << ", " << ans0.second;
    } else {
        cout << "\nTarget pair sum NOT found!!";
    }

    vector<int> vec1 = {1, 4, 7, 9, 24, 32, 61};    // Sorted Vector
    pair<int, int> ans1 = findTarget(vec1, 10 /*target*/);
    if(ans1.first >= 0 && ans1.second >= 0) {
        cout << "\nAns: " << ans1.first << ", " << ans1.second;
    } else {
        cout << "\nTarget pair sum NOT found!!";
    }

    vector<int> vec2 = {3, 5, 8, 9, 12, 14};    // Sorted Vector
    pair<int, int> ans2 = findTarget_Optimal(vec2, 26 /*target*/);
    if(ans2.first >= 0 && ans2.second >= 0) {
        cout << "\nAns: " << ans2.first << ", " << ans2.second;
    } else {
        cout << "\nTarget pair sum NOT found!!";
    }
    
    return 0;
}
