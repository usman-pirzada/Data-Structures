/*
A secret agent is sending coded messages to their partner. To ensure security, the agent uses
a letter-substitution scheme: each letter in the original message is replaced consistently with
another letter to generate the coded message.
For example:
  ● Original message: "egg"
  ● Coded message: "add"
The agent wants to check if two messages could have been encoded from each other using a
consistent letter-substitution scheme.
Given two messages (strings) s1 and s2:
  ● Both strings consist of only lowercase English letters
  ● Both strings have equal length
Write a C++ program which will check if s1 and s2 are isomorphic, meaning:
  1. Each character in s1 can be replaced to get s2
  2. A character can map to itself
  3. No two characters in s1 can map to the same character in s2
*/
#include <iostream>
using namespace std;

bool isIsomorphic(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }

    char map1[26] = {0};
    char map2[26] = {0};

    for(int i=0; i<s1.length(); i++) {
        int idx1 = s1[i] - 'a';
        int idx2 = s2[i] - 'a';

        if(map1[idx1] != 0 && map1[idx1] != s2[i]) {
            return false;
        } 
        else if(map2[idx2] != 0 && map2[idx2] != s1[i]) {
            return false;
        }
            
        map1[idx1] = s2[i];
        map2[idx2] = s1[i];
    }

    return true;
}

int main() {
    string s1 = "egg";
    string s2 = "add";

    if(isIsomorphic(s1, s2)) {
        cout << "Strings are Isomorphic\n";
    } else {
        cout << "Strings are NOT Isomorphic\n";
    }
    
    return 0;
}