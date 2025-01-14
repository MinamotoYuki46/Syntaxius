// LeetCode Problem: Ransom Note
// Problem URL: https://leetcode.com/problems/ransom-note/
// Difficulty: Easy
// Solution Date: 30 October 2024

// Problem Statement:
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Approach:
// store each char in the unordered map, then compare each other. If char from ransomNote > magazine, it's fasle, otherwise true

// Complexity Analysis:
// Time Complexity: O(n) - inserting each char of both array then comparing
// Space Complexity: O(1) - just storing 26 lowercase letter

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> mapRansomNote, mapMagazine;

        for(auto i: magazine){
            mapMagazine[i]++;
        }

        for(int i: ransomNote){
            mapRansomNote[i]++;
        }

        for(auto key: ransomNote){
            if (mapRansomNote[key] > mapMagazine[key]){
                return false;
            }
        }

        return true;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    
    string ransomNote = "aa", magazine = "aab";

    bool result = sol.canConstruct(ransomNote, magazine);
    cout << "Result: " << result << endl;
    return 0;
}