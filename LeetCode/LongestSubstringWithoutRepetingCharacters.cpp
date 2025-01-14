// LeetCode Problem: Longest Substring Without Repeating Characters
// Problem URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Solution Date: 26 October 2024

// Problem Statement:
// Given a string s, find the length of the longest substring without repeating characters.

// Approach:
// we try to include each substring (char) into the map and mark the initial index of the substring. Once we encounter same
// char that has been stored, we set the same char to the current index and count again while compare it to previous substring size

// Complexity Analysis:
// Time Complexity: O(n) - we need to traverse the string
// Space Complexity: O(min(m,n)) - to store each char (m)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ptr = 0;
        int res = 0;
        unordered_map<char, int> mci;

        for(int i = 0; i < s.length(); i++){
            if (mci.count(s[i]) == 0 || mci[s[i]] < ptr){
                mci[s[i]] = i;
                res = max(res, i - ptr + 1);
            }
            else{
                ptr = mci[s[i]] + 1;
                mci[s[i]] = i;
            }
        }
        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    string str = "pwwkew";

    int result = sol.lengthOfLongestSubstring(str);
    cout << "Result: " << result << endl;
    return 0;
}