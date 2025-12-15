#include <iostream>
using namespace std;

int stringSearch(string txt, string pattern) {  // Brute Force Approach
    int n = txt.length();
    int m = pattern.length();

    for(int i=0; i <= n - m; i++) {
        int j=0;

        while(j < m && txt[i+j] == pattern[j]) {
            j++;
        }
        if(j == m) return i;
    }

    return -1;
}

int main() {
    
    cout << stringSearch("Programming", "gram") << endl;
    
    return 0;
}
