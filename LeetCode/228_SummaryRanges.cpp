// LeetCode Problem: Summary Ranges
// Problem URL: https://leetcode.com/problems/summary-ranges/
// Difficulty: Easy
// Solution Date: 27 October 2024

// Problem Statement:
// You are given a sorted unique integer array nums.
// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
// That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:
// "a->b" if a != b
// "a" if a == b

// Approach:
// using 2 pointer to track begin and end of range. if the difference current num and next is more than 1, start over

// Complexity Analysis:
// Time Complexity: O(n) - to traverse
// Space Complexity: O(n) - worst case, there is no range so it can add up to n also

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans = {};
        if (nums.size() == 0) return ans;

        int ff = nums[0], ss = nums[0];

        for (int i = 1; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == ss + 1) {
                ss = nums[i];
            } 
            else {
                if (ff == ss) {
                    ans.push_back(to_string(ff));
                } 
                else {
                    ans.push_back(to_string(ff) + "->" + to_string(ss));
                }

                if (i < nums.size()) {
                    ff = ss = nums[i];
                }
            }
        }
        return ans;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<int> nums = {0,1,2,4,5,7};

    vector<string> result = sol.summaryRanges(nums);
    // cout << "Result: " << result << endl;
    for(auto i : result){
        cout << i << ',';
    }
    return 0;
}