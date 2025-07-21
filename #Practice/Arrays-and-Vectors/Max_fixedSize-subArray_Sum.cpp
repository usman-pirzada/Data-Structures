/**
 *      "MAXIMUM FIXED-SIZE SUB-ARRAY SUM"
 * Given an array of integers, find the maximum sum of a contiguous subarray of a fixed size.
 * 
 * SOLUTION:
 * Brute Force Approach [O(n²)]:
 *  This approach finds all possible subarrays of the fixed size by:
 *      1. Using two nested loops to generate each subarray of the required size
 *      2. Calculating the sum for each subarray
 *      3. Tracking and updating the maximum sum found so far
 *  Note: We initialized maxSum to INT_MIN rather than vec[0] to handle edge cases correctly,
 *  especially when all elements are negative or the array is smaller than the subarray size.
 * 
 * Sliding Window Approach [O(n)]:
 *  This optimized approach uses a sliding window technique by:
 *      1. Calculating the sum of the first windowSize elements
 *      2. Sliding the window one element at a time:
 *         - Subtract the element leaving the window
 *         - Add the element entering the window
 *      3. Tracking the maximum sum encountered
 *  This reduces the time complexity from O(n²) to O(n) by avoiding recalculating the entire sum for each window.
 * 
 * Space Complexity:
 *  - Both approaches have O(1) space complexity for their calculations
 *  - With reference parameter (`&` in `vector<int>& vec`): Space complexity remains O(1) for the function itself
 *  - Without reference: Space complexity becomes O(n) for the function due to the vector copy
 */

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//       ~~~~~ Brute Force Approach  [O(n²)] ~~~~~
int max_fixedSizeSubArray_sum(vector<int>& vec, int subArray_size) {
    if (vec.empty()) {
        cout << "Error: Input array is empty!" << endl;
        exit(1);
    }
    if (subArray_size <= 0 || subArray_size > vec.size()) {
        cout << "Error: Invalid window size!" << endl;
        exit(1);
    }

    int maxSum = INT_MIN;
    /**
     * Here initializing maxSum to vec[0] is unsafe because:
     *  1. vec[0] is just the first element, not the sum of the first window when subArray_size > 1.
     *  2. If vec[0] is larger (or less negative) than any actual window sum, you’ll return an invalid result that doesn’t correspond to any full subarray of the requested size.
     */

    for (size_t i = 0; i <= vec.size() - subArray_size; i++) {
        int currentSum = 0;

        for (int j = i; j < i + subArray_size; j++) {
            currentSum += vec[j];
        }
        maxSum = max(currentSum, maxSum);
    }

    return maxSum;
}

//       ~~~~~ Sliding Window Approach  [O(n)] ~~~~~
int max_fixedSizeSubArray_sum_OPTIMAL(vector<int>& vec, int windowSize) {
    if (vec.empty()) {
        cout << "Error: Input array is empty!" << endl;
        exit(1);
    }
    if (windowSize <= 0 || windowSize > vec.size()) {
        cout << "Error: Invalid window size!" << endl;
        exit(1);
    }

    int currentSum = 0;

    for (size_t i = 0; i < windowSize; i++) {
        currentSum += vec[i];
    }
    int maxSum = currentSum;

    for (size_t i = 1; i <= vec.size() - windowSize; i++) {
        currentSum -= vec[i - 1];
        currentSum += vec[i + windowSize - 1];

        if(currentSum > maxSum) maxSum = currentSum;
    }

    return maxSum;
}

int main() {

    vector<int> vec1 = {3, -4, 5, 4, -1, 7, 8};
    cout << "\nMax (fixed-size) Subarray Sum: " << max_fixedSizeSubArray_sum(vec1, 3) << endl;
    cout << "Max (fixed-size) Subarray Sum: " << max_fixedSizeSubArray_sum_OPTIMAL(vec1, 3) << endl;

    vector<int> vec2 = {-7, -3, 10, -10, 2, -8, -5, -9, -4, -6};
    cout << "\nMax (fixed-size) Subarray Sum: " << max_fixedSizeSubArray_sum(vec2, 4) << endl;
    cout << "Max (fixed-size) Subarray Sum: " << max_fixedSizeSubArray_sum_OPTIMAL(vec2, 4) << endl;

    vector<int> vec3 = {3, 8, 2, 5, 7, 6, 12};
    cout << "\nMax (fixed-size) Subarray Sum: " << max_fixedSizeSubArray_sum(vec3, 4) << endl;
    cout << "Max (fixed-size) Subarray Sum: " << max_fixedSizeSubArray_sum_OPTIMAL(vec3, 4) << endl;

    return 0;
}
