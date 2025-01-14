// LeetCode Problem: 3 Sum
// Problem URL: https://leetcode.com/problems/3sum
// Difficulty: Medium
// Solution Date: 11 December 2024

// Problem Statement:
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Constraint
// 
// 3 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5


// Approach:
// The two-pointer approach in the given solution efficiently finds all unique triplets that sum up to zero. First, the array is sorted, which allows the use of
// two pointers to avoid duplicates and reduce the search space. The outer loop picks each element nums[i] as the first element of a potential triplet. For each i,
// two pointers are set: j starts just after i and k starts at the end of the array. These pointers move toward each other based on the sum of the triplet. 
// If the sum is greater than zero, the k pointer moves left to reduce the sum, and if the sum is less than zero, the j pointer moves right to increase the sum. When a 
// valid triplet is found (sum == 0), it is added to the result, and duplicates are avoided by skipping over duplicate elements with the j pointer. This approach 
// reduces the time complexity from O(n^3) to O(n^2), making it much more efficient for large inputs.

// Complexity Analysis:
// Time Complexity: O(n^2) - traverse and checking
// Space Complexity: O(1) - only storing res

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) k--;
                else if (total < 0) j++;
                else{
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }
        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> result = sol.threeSum(nums);
    
    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}