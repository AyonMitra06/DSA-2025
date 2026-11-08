#include <bits/stdc++.h>
/* 
Permutation in String
Medium
Topics
Company Tags
Hints
You are given two strings s1 and s2.

Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.

Both strings only contain lowercase letters.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string sortedS1 = s1;
        sort(sortedS1.begin(), sortedS1.end());
        for(int i = 0; i<s2.size(); i++){
            string subString = s2.substr(i,s1.size());
            sort(subString.begin(), subString.end());
            
            if(sortedS1 == subString){
                return true;
            }
        }
        return false;
    }
};
