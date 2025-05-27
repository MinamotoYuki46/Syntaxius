// LeetCode Problem: Trapping Rain Water
// Problem URL: https://leetcode.com/problems/trapping-rain-water
// Difficulty: Hard
// Solution Date: 23 March 2025

// Problem Statement:
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Constraint
// 
// n == height.length
// 1 <= n <= 2 * 10^4
// 0 <= height[i] <= 10^5


// Approach:
// use two pointer. At each step, the smaller of the two heights at the pointers determines the direction of movement

// Complexity Analysis:
// Time Complexity: O(n) - only iterating till both pointer meet
// Space Complexity: O(1) - only defines the pointer, the res, and element ponted by pointer

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int water = 0;
            int leftBlock = height[left], rightBlock = height[right];

            while(left < right){
                if (leftBlock < rightBlock){
                    left++;
                    leftBlock = max(leftBlock, height[left]);
                    water += leftBlock -  height[left];
                }
                else {
                    right--;
                    rightBlock = max(rightBlock, height[right]);
                    water += rightBlock - height[right];
                } 
            }

            return water;
        }
    };

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = sol.trap(test);
    cout << "Result: " << result << endl;
    return 0;
}