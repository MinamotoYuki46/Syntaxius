// LeetCode Problem: Two Sum
// Problem URL: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Solution Date: 24 October 2024

// Problem Statement:
// Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Approach:
// - Use a hash map to store each element's value and its index as we iterate through `nums`.
// - For each element, calculate the complement by subtracting the element's value from `target`.
// - If the complement exists in the map, return the indices of the complement and the current element.
// - Otherwise, add the element to the map for future reference.

// Complexity Analysis:
// Time Complexity: O(n) - where n is the number of elements in `nums`.
// Space Complexity: O(n) - due to the hash map storing up to n elements.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mii;  
        for (int i = 0; i < nums.size(); i++) {  
            int comp = target - nums[i];  
            if (mii.find(comp) != mii.end()) {  
                return {mii[comp], i};  
            }
            mii[nums[i]] = i;  
        }
        return {};  
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
