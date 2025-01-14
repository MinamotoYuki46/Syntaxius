// LeetCode Problem: Containts Duplicate
// Problem URL: URL
// Difficulty: Easy
// Solution Date: 29 October 2024

// Problem Statement:
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Approach:
// make unordered set, then compare. if there is second (which mean already insertead) then return true

// Complexity Analysis:
// Time Complexity: O(n) - Explain
// Space Complexity: O(n) - Explain

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num;

        for(int i = 0; i < nums.size(); i++){
            if (!num.insert(nums[i]).second) return true;
        }

        return false;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};

    bool result = sol.containsDuplicate(nums);
    cout << "Result: " << result << endl;
    return 0;
}