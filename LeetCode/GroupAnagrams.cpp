// LeetCode Problem: Group Anagrams
// Problem URL: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium
// Solution Date: Medium

// Problem Statement:
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Approach:
// Explain approach here.

// Complexity Analysis:
// Time Complexity: O(n ⋅ klogk) - sorting each string takes O (k log k) time 
// Space Complexity: O(n ⋅ k) - where 𝑛 is the number of strings and 𝑘 is the average length of the strings.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            anagramGroups[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);
    cout << "Result: " << endl;
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}