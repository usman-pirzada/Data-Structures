/**
 *      "MAXIMUM SUB-ARRAY SUM by Brute Force Approach & Kadane's Algorithm"
 * Given an array of integers, find the maximum sum of any contiguous subarray.
 * 
 * SOLUTION:
 * Brute Force Approach [O(n²)]: Use two nested loops to consider every possible subarray, calculate each sum, and track the highest one (O(n²)).
 *  This approach finds all possible subarrays by:
 *      1. Using two nested loops to generate each subarray
 *      2. Calculating the sum for each subarray
 *      3. Tracking and updating the maximum sum found so far
 *  Note: For each start position, we consider all possible ending positions including the start position itself as ending position.
 * 
 * Kadane’s Algorithm [O(n)]:
 *  This approach tracks the maximum subarray sum by:
 *      1. Maintaining a running sum (currentSum)
 *      2. Comparing currentSum with the overall maximum (maxSum) at each step
 *      3. Resetting currentSum to 0 whenever it becomes negative
 *  Note: We compare maxSum with currentSum first, then reset currentSum if needed.
 *  This preserves the correct result when all elements are negative.
 * 
 * Space Complexity:
 *  - With reference parameter (`&` in `vector<int>& vec`): Space complexity remains O(1) for the function itself
 *  - Without reference: Space complexity becomes O(n) for the function due to the vector copy
 */

#include <iostream>
// #include <algorithm>
#include <vector>
using namespace std;

//      ~~~~~ Brute Force Approach [O(n²)] ~~~~~
int maxSubArraySUM(vector<int>& vec) {
    if(vec.empty()) return 0;

    int maxSum = vec[0];   // Can also be ```int maxSum = INT_MIN;```
    int a = INT_MIN;

    for (size_t i = 0; i < vec.size(); i++) {
        int currentSum = 0;

        for (int j = i; j < vec.size(); j++) {
            currentSum += vec[j];
            maxSum = max(currentSum, maxSum);
        }
    }
    return maxSum;
}

//       ~~~~~ Kadane's Algorithm Approach  [O(n)] ~~~~~
int maxSubArraySUM_Optimal(vector<int>& vec) {
    if(vec.empty()) return 0;

    int maxSum, currentSum = vec[0];   // Can also be ```int maxSum = INT_MIN, int currentSum = 0;```

    for (size_t i = 1; i < vec.size(); i++) {
        currentSum += vec[i];
        maxSum = max(currentSum, maxSum);

        if(currentSum < 0) currentSum = 0;

        /*
                    OR
        currentSum = max(currentSum + vec[i], vec[i]);
        maxSum = max(maxSum, currentSum);

        (Here 'if' for resetting 'currentSum' is not needed.)
        */
    }
    return maxSum;
}

int main() {

    vector<int> vec1 = {3, -4, 5, 4, -1, 7, -8};
    cout << "Max Subarray Sum: " << maxSubArraySUM(vec1) << endl;
    cout << "Max Subarray Sum: " << maxSubArraySUM_Optimal(vec1) << endl;

    vector<int> vec2 = {-7, -3, 10, -10, 2, -8, -5, -9, -4, -6};
    cout << "\nMax Subarray Sum: " << maxSubArraySUM(vec2) << endl;
    cout << "Max Subarray Sum: " << maxSubArraySUM_Optimal(vec2) << endl;

    return 0;
}
