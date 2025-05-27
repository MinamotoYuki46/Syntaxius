// LeetCode Problem: Product of Array Except Self
// Problem URL:https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Solution Date: 29 October 2024

// Problem Statement:
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Approach:
// using prefix to store the product of the beginning of the array up to end (exlusive) 
// and suffix to store the product of the end of the array up to beginning (exlusive) 
// then the product is prefix[i] * suffix[i]

// Complexity Analysis:
// Time Complexity: O(n) - to traverse twice
// Space Complexity: O(1) - to store temp value

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result (n,1);

        int prefix = 1;
        for (int i = 0;i < n;i++) {
            result[i] *= prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = n - 1 ;i >= 0;i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        
        return result;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<int> nums = {-1, 1, 0, 3, -3};

    vector<int> result = sol.productExceptSelf(nums);
    
    for(auto i:result){
        cout << i << ' ';
    }
    return 0;
}