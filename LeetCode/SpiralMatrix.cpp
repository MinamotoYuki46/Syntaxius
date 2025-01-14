// LeetCode Problem: Spiral Matrix
// Problem URL: https://leetcode.com/problems/spiral-matrix/
// Difficulty: Medium
// Solution Date: 29 October 2024

// Problem Statement:
// Given an m x n matrix, return all elements of the matrix in spiral order.

// Approach:
// print left to right, top to bottom, right to left, bottom to top, while keep tracking the used index

// Complexity Analysis:
// Time Complexity: O(m * n) - same as the dimension of the array input
// Space Complexity: O(i) - to store the tracking u, b, r, l

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int u = 0, b = matrix[0].size() - 1, l = 0, r = matrix.size() - 1;
        vector<int> res;

        while(u <= b && l <= r){
            for(int i = l; i <= r; i++){
                res.push_back(matrix[u][i]);
            }
            u++;

            for(int i = u; i <= b; i++){
                res.push_back(matrix[i][r]);
            }
            r--;

            if (u <= b){
                for(int i = r; i >= l; i--){
                    res.push_back(matrix[b][i]);
                }
                b--;
            }

            if (l <= r){
                for(int i = b; i >= u; i--){
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<vector<int>> mat = { {1,2,3},
                                {4,5,6},
                                {7,8,9}
                                };


    vector<int> result = sol.spiralOrder(mat);

    for(auto i: result){
        cout << i << ' ';
    }

    return 0;
}