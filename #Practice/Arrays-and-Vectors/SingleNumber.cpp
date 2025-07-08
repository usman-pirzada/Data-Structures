/**
     *              "SINGLE NUMBER"
     * Given a non-empty array of integers nums, every element appears twice except for one.
     * Find that single one.
     * You must implement a solution with a linear runtime complexity and use only constant extra space.
     * https://leetcode.com/problems/single-number
     * 
     * SOLUTION:
     * We'll utilize the bitwise XOR (^) operator. XOR has the property that:
     *   n ^ n = 0 (a number XORed with itself is 0)
     *   n ^ 0 = n (a number XORed with 0 is the number itself)
     * 
     * Applying XOR across all elements will cancel out the duplicate pairs,
     * leaving only the unique number as the final result.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> vec = {4,1,2,1,2};
    
    int ans = 0;
    for(int val : vec) {
        ans ^= val;
    }
    cout << "Answer: " << ans << endl;
    
    return 0;
}
