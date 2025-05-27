// LeetCode Problem: Majority Element
// Problem URL: https://leetcode.com/problems/majority-element
// Difficulty: Easy
// Solution Date: 16 November 2024

// Problem Statement:
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Follow-up: Could you solve the problem in linear time and in O(1) space?

// Approach:
// using Boyer–Moore majority vote algorithm
// from wikipedia:
// The algorithm maintains in its local variables a sequence element and a counter, 
// with the counter initially zero. It then processes the elements of the sequence, o
// ne at a time. When processing an element x, if the counter is zero, the algorithm stores x as its remembered sequence element and 
// sets the counter to one. Otherwise, it compares x to the stored element and either increments the counter (if they are equal) or 
// decrements the counter (otherwise). At the end of this process, if the sequence has a majority, it will be the element stored by the algorithm.

// Complexity Analysis:
// Time Complexity: O(n) - to traverse
// Space Complexity: O(1) - to store 2 vars

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {3,2,3};
    int result = sol.majorityElement(nums);
    cout << "Result: " << result << endl;
    return 0;
}