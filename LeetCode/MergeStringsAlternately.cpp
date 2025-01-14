// LeetCode Problem: Merge Strings Alternately
// Problem URL: https://leetcode.com/problems/merge-strings-alternately/
// Difficulty: Easy
// Solution Date: 27 January 2024

// Problem Statement:
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
// If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

// Approach:
// First, find the min length of both strings. Then, for each traverse, put the i-th of word1 and word2. If there's left, just combined.

// Complexity Analysis:
// Time Complexity: O(max(len(word1),len(word2))) - to traverse both strings
// Space Complexity: O(len(word1) + len(word2)) - to combine tbith strings

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string strMerge;
        int len = min(word1.length(), word2.length());
        for(int i = 0 ; i < len; i++){
            strMerge.push_back(word1[i]);
            strMerge.push_back(word2[i]);
        }
        strMerge += word1.substr(len) + word2.substr(len);
        return strMerge;
    }
};



int main() {
    string word1 = "abc", word2 = "pqr";

    Solution sol;
    string merged = sol.mergeAlternately(word1, word2);
    cout << merged << endl;
    return 0;
}
