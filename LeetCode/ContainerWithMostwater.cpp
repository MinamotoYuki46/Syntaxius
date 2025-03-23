// LeetCode Problem: Container with Most Water
// Problem URL: https://leetcode.com/problems/container-with-most-water
// Difficulty: Medium
// Solution Date: 23 March 2025

// Problem Statement:
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Constraint
// 
// n == height.length
// 2 <= n <= 10^5
// 0 <= height[i] <= 10^4


// Approach:
// use two pointer. we try to calculate the current edges (0 and n - 1) and store it in the max variable. Then try to move the pointer until both are met at same position (value)

// Complexity Analysis:
// Time Complexity: O(n) - iterating the array
// Space Complexity: O(1) - just allocating some variables

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int curRect = 0, maxRect = 0, n = height.size();
            int left = 0, right = n - 1;
            int width = 0;

            while (left < right){
                width = right - left;
                curRect = min(height[left], height[right]) * width;
                maxRect = max(maxRect, curRect);
                
                if (height[left] < height[right]) left++;
                else right--;
            }

            return maxRect;
        }
    };

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> test = {1,8,6,2,5,4,8,3,7};
    int result = sol.maxArea(test);
    cout << "Result: " << result << endl;
    return 0;
}