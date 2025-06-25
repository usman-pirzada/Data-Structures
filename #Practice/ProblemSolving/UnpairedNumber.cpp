/**
 *      "Unpaired Number"
 * Given an array where every positive number has its corresponding negative counterpart except for one unique number.
 * Identify and print that number.
 * 
 * SOLUTION:
 * The sum of all elements gives the unmatched number, as each +ve and -ve pair cancels out.

 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> vec = {2, 45, 74, 32, -45, -32, -2, 61, -74};

    int ans = 0;
    for(int val : vec) {
        ans += val;
    }
    cout << "The required number is \"" << ans << "\".\n\n";
    
    return 0;
}
