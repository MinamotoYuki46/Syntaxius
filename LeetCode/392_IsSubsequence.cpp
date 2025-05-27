// LeetCode Problem: Is Subsequence
// Problem URL: https://leetcode.com/problems/is-subsequence/description/
// Difficulty: Easy 
// Solution Date: 28 July 2024

// Problem Statement:
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without 
// disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Approach:
// First make 2 pinter to track the index, then iterates. If the s[CurS] matches t[CurT], increment the CurS. Increment the CurT for each iteration

// Complexity Analysis:
// Time Complexity: O(n + m.) - iterates through each character of t at most once, making it linear in relation to the lengths of s and t.
// Space Complexity: O(1) - just to jeep track the CurS and CurT pointers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int curS = 0, curT = 0;

        while (curS < s.size() && curT < t.size()){
            if (s[curS] == t[curT]) curS++;
            curT++;
        }

        return curS == s.size()? true:false;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    string s = "abc", t = "ahbgdc";
    bool result = sol.isSubsequence(s, t);
    cout << "Result: " << result << endl;
    return 0;
}