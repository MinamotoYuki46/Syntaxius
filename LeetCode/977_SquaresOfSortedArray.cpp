// LeetCode Problem: Squares of a Sorted Array
// Problem URL: https://leetcode.com/problems/squares-of-a-sorted-array
// Difficulty: Easy
// Solution Date: 19 Novemebr 2024

// Problem Statement:
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

// Constraint
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

// Approach:
// Since the original array is not sorted, it's not guaranteed 
// that the largest elements (in terms of absolute value) 
// are at the ends of the array.

// By iterating backwards from the end of the array, we can 
// start populating the result array from the end, ensuring 
// that the squares of larger elements occupy the higher 
// indices of the result array.

// Complexity Analysis:
// Time Complexity: O(n) - traverse
// Space Complexity: O(n) - create vi res (n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        vector<int> res (n);

        for(int i = n - 1 ; i >= 0; i--){
            if (abs(nums[l]) >= abs(nums[r])){
                res[i] = nums[l] * nums[l];
                l++;
            }
            else {
                res[i] = nums[r] * nums[r]; 
                r--;
            }
        }

        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {-4, -1, 0 , 3, 10};

    vector<int> result = sol.sortedSquares(nums);
    
    for(int num : result){
        cout << num << ' ';
    }
    return 0;
}