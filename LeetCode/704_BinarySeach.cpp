// LeetCode Problem: Binary Search
// Problem URL: leetcode.com/problems/binary-search
// Difficulty: Easy
// Solution Date: 6 November 2025

// Problem Statement:
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.


// Constraint
// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.


// Approach:
// basically, use binary search (as it name suggested)

// Complexity Analysis:
// Time Complexity: O(log(n)) - binary search
// Space Complexity: O(1) - aux storing

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector a = {-1, 0, 3, 5, 9, 12};
    int result = sol.search(a, 9);
    cout << "Result: " << result << endl;
    return 0;
}