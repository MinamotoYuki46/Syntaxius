// LeetCode Problem: Valid Anagram
// Problem URL: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy
// Solution Date: 30 October 2024

// Problem Statement:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Approach:
// make an unordered map to track the letter, when the char in s exist, add to umap. While exist in t, subtract the umap 
// if both anagram, the total umap key must be zero

// Complexity Analysis:
// Time Complexity: O(n) - inserting to umap
// Space Complexity: O(1) - just storing 26 alphabet 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map <char, int> umap;

        for(int i = 0; i < s.length(); i++){
            umap[s[i]]++;
            umap[t[i]]--;
        }

        for (const auto& pair : umap) {
            if (pair.second != 0) {
                return false; 
            }
        }

        return true;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    string s = "anagram", t = "nagaram";

    bool result = sol.isAnagram(s, t);
    cout << "Result: " << result << endl;
    return 0;
}