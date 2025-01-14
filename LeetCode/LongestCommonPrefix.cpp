// LeetCode Problem: Longest Common Prefix
// Problem URL: https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy
// Solution Date: 26 October 2024

// Problem Statement:
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Approach:
// sort the order of the string, then compare vertically. if the char mismatch break

// Complexity Analysis:
// n is the vector size, m the length of the string
// Time Complexity: O(nlogn m) - nlogn for sorting, m for traverse and scan
// Space Complexity: O(m) - to store the res

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        sort(strs.begin(), strs.end());

        int n = strs.size();

        string first = strs[0], last = strs[n - 1]; 

        for(int i = 0; i < min(first.size(), last.size()); i++){
            if (first[i] != last[i]) return res;

            res += first[i];
        }
        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    string result = sol.longestCommonPrefix(strs);
    cout << "Result: " << result << endl;
    return 0;
}