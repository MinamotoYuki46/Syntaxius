// LeetCode Problem: Longest Consecutive Sequence
// Problem URL: https://leetcode.com/problems/longest-consecutive-sequence
// Difficulty: Hard
// Solution Date: 16 November 2024

// Problem Statement:
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Approach:
// use a set or unordered set to track the elements, and then for each element, check whether it starts a 
// new consecutive sequence (i.e., num - 1 is not in the set). By doing this, we can efficiently find the longest consecutive subsequence.

// Complexity Analysis:
// Time Complexity: O(n) - insertion and finding consecutive sequence
// Space Complexity: O(n) - store the hash set

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set <int> numSet (nums.begin(), nums.end());
        int longestStreak = 0;

        for(int num : numSet){
            if (numSet.find(num - 1) == numSet.end()){
                int curNum = num;
                int curStreak = 1;

                while(numSet.find(curNum + 1) != numSet.end()){
                    curNum++;
                    curStreak++;
                }
                longestStreak = max(longestStreak, curStreak);
            }
        }
        return longestStreak;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> nums {100,4,200,1,3,2};
    int result = sol.longestConsecutive(nums);
    cout << "Result: " << result << endl;
    return 0;
}