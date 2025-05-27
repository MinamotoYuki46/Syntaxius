// LeetCode Problem: Two Sum II - Input Array Is Sorted
// Problem URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
// Difficulty: Medium
// Solution Date: 20 November 2024

// Problem Statement:
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.

// Constraint
// 2 <= numbers.length <= 3 * 104
// -1000 <= numbers[i] <= 1000
// numbers is sorted in non-decreasing order.
// -1000 <= target <= 1000
// The tests are generated such that there is exactly one solution.

// Approach:
// a little bit similiar with binary search. keep tracking l, r, and sum

// Complexity Analysis:
// Time Complexity: O(n) - comparing 2 pointer on single loop
// Space Complexity: O(1) - to store pointers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;

        while(l < r){
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {++l, ++r};
            else if (sum > target) r--;
            else l++;
        }
        return {};
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    
    for(auto i: result){
        cout << i << ' ';
    }
    return 0;
}