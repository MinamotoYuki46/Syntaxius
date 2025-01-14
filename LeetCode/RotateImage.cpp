// LeetCode Problem: Rotate Image
// Problem URL: https://leetcode.com/problems/rotate-image/
// Difficulty: Medium
// Solution Date: 29 October 2024

// Problem Statement:
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Approach:
// transpose the matrix, then swap the each column

// Complexity Analysis:
// Time Complexity: O(n^2) - traversing 2D array
// Space Complexity: O(1) - just for r and c

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        // Transpose
        for(int i = 0; i < r; i++){
            for(int j = i + 1; j < c; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Swap each column;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c/2; j++){
                swap(matrix[i][j], matrix[i][c - j - 1]);
            }
        }
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector<vector<int>> mat = { 
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    sol.rotate(mat);
    
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << '\n';
    }

    return 0;
}