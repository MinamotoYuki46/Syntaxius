// LeetCode Problem: Remove Duplicates from Sorted Array
// Problem URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Solution Date: 27 October 2024

// Problem Statement:
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
// The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Approach:
// the function is to return k (the first k element to return) while move the unique number so that when print up to k - 1, all num is unique.
// basically when current num is difference with prev num, change that prev num to cur num and record the k or index

// Complexity Analysis:
// Time Complexity: O(n) - to traverse
// Space Complexity: O(1) - to store k or index

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 1;

        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i - 1]){
                nums[x] = nums[i];
                x++;
            }
        }
        return x;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int result = sol.removeDuplicates(nums);
    cout << "Result: " << result << endl;
    return 0;
}