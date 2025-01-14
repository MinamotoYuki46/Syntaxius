// LeetCode Problem: Merge Interval
// Problem URL: https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium
// Solution Date: 29 October 2024

// Problem Statement:
// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Approach:
// greedy approach. first sort the vector, then compare interval[i].back and interval[i+1].front.
// If the interval[i+1].front <= interval[i].back, combine these into one part

// Complexity Analysis:
// Time Complexity: O(n log n) - n log n for sorting, then swapping
// Space Complexity: O(n) - to store result

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        vector<vector<int>> res;

        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            vector<int>& lastInterval = res.back();

            if (intervals[i][0] <= lastInterval[1]) {
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } 
            else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};

    vector<vector<int>> result = sol.merge(intervals);

    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}