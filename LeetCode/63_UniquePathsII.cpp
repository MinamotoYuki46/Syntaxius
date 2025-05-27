// LeetCode Problem: Unique Paths
// Problem URL: https://leetcode.com/problems/unique-paths/
// Difficulty: Medium
// Solution Date: 17 January 2025

// Problem Statement:
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Constraint
// 1 <= m, n <= 100

// Approach:
// using DP. First initialize 2D DP array m * n with default value 0 for all element. then for 1 to n -1 or m - 1, calculate by adding upper and left cell value
// suppose a cell dp[i][j], the only way to reach that cell is either comming from up or left, that's why we need to add the dp[i-1][j] and dp[i][j-1]
// Addition: for the obstacle, we make it dp value in that exact cell, rest right, and rest bottom to be zero, then set the addition condition only happen in non-obstacle cell

// Complexity Analysis:
// Time Complexity: O(m * n) - to traverse for each element in the 2D DP
// Space Complexity: O(m * n) - to create the 2D array of DP

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();


        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;

        for (int i = 1; i < m; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 0) ? dp[i-1][0] : 0;
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = (obstacleGrid[0][j] == 0) ? dp[0][j-1] : 0;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if (!obstacleGrid[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        return dp[m-1][n-1];
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;

    vector<vector<int>> arr = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    // Example test case
    int result = sol.uniquePathsWithObstacles(arr);
    cout << "Result: " << result << endl;
    return 0;
}