// todo: Add comment

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//       ~~~~~ Brute Force Approach  [O(n²)] ~~~~~
int max_fixedSizeSubArray_sum(vector<int>& vec, int subArray_size) {
    int maxSum = INT_MIN;   // todo: Why not int maxSum = vec[0]

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
