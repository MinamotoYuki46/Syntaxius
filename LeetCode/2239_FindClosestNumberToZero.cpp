// LeetCode Problem: Find Closest Number to Zero
// Problem URL: https://leetcode.com/problems/find-closest-number-to-zero/
// Difficulty: Easy
// Solution Date: 26 October 2024

// Problem Statement:
// Given an integer array nums of size n, return the number with the value closest to 0 in nums. 
// If there are multiple answers, return the number with the largest value.

// Approach:
// Using greedy approach, make the negative number into positive using absolute. First comparison to check if the abs(x) smaller than current result
// then if we have duplicate (x and -x), we make sure to take the largest (positive) one 

// Complexity Analysis:
// Time Complexity: O (n)) - To traverse the vector
// Space Complexity: O(1) - just to store the temp and res

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = INT_MAX;
        int x;

        for(int i = 0; i < nums.size(); i++){
            x = abs(nums[i]);

            if (x < abs(res) || (x == abs(res) && nums[i] > res)){
                res = nums[i];
            }
        }
        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<int> nums = {-4,-2,1,4,8};
    int result = sol.findClosestNumber(nums);
    cout << "Result: " << result << endl;
    return 0;
}