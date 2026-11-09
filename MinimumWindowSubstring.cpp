#include <bits/stdc++.h>
using namespace std;
/*
Minimum Window Substring

Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

You may assume that the correct output is always unique.
*/
class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        int need[128] = {0};
        int window[128] = {0};

        // Store the required frequencies
        for (char c : t) {
            need[c]++;
        }

        int required = 0;

        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // PHASE 1: Expand the window

            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            // PHASE 2: Shrink the window

            while (formed == required) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char removed = s[left];
                window[removed]--;

                if (need[removed] > 0 &&
                    window[removed] < need[removed]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};