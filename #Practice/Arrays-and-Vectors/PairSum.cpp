#include <iostream>
#include <vector>
using namespace std;

vector<int> findTarget(vector<int>& vec, int targetSum) {   // Valid for Sorted/Unsorted Vectors
    vector<int> indexVec;

    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i+1; j < vec.size(); j++) {

            if(vec[i] + vec[j] == targetSum) {
                indexVec.push_back(i);
                indexVec.push_back(j);

                return indexVec;
            }
        }
    }
    
    return indexVec;
}

vector<int> findTarget_Optimal(vector<int>& vec, int targetSum) {   // Valid for Sorted Vectors ONLY
    vector<int> indexVec;

    int start = 0, end = vec.size() - 1;
    
    while(start < end) {
        int pairSum = vec[start] + vec[end];

        if(pairSum < targetSum) {
            start++;
        } else if(pairSum > targetSum) {
            end--;
        } else {
            indexVec.push_back(start);
            indexVec.push_back(end);

            return indexVec;
        }
    }

    return indexVec;
}

int main() {

    vector<int> vec0 = {61, 9, 7, 4, 24, 32, 1};    // Unsorted Vector
    vector<int> ans0 = findTarget(vec0, 10/*target*/);
    if(ans0.size() != 0) {
        cout << "\nAns: " << ans0[0] << ", " << ans0[1];
    } else {
        cout << "\nTarget pair sum NOT found!!";
    }

    vector<int> vec1 = {1, 4, 7, 9, 24, 32, 61};    // Sorted Vector
    vector<int> ans1 = findTarget(vec1, 10/*target*/);
    if(ans1.size() != 0) {
        cout << "\nAns: " << ans1[0] << ", " << ans1[1];
    } else {
        cout << "\nTarget pair sum NOT found!!";
    }

    vector<int> vec2 = {3, 5, 8, 9, 12, 14};    // Sorted Vector
    vector<int> ans2 = findTarget_Optimal(vec2, 26/*target*/);
    if(ans2.size() != 0) {
        cout << "\nAns: " << ans2[0] << ", " << ans2[1];
    } else {
        cout << "\nTarget pair sum NOT found!!";
    }
    
    return 0;
}
