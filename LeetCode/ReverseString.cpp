// LeetCode Problem: Reverse String
// Problem URL: https://leetcode.com/problems/reverse-string
// Difficulty: Easy
// Solution Date: 20 November 2024

// Problem Statement:
// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Constraint
// 1 <= s.length <= 105
// s[i] is a printable ascii character.

// Approach:
// swap each element l and r until mid-th element

// Complexity Analysis:
// Time Complexity: O(n) - traverse from front to mid (n/2)
// Space Complexity: O(1) - just to store the pointer

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(), l = 0, r = n - 1;

        for(int i = 0; i < n/2; i++){
            swap(s[l], s[r]);
            l++; r--;
        }
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<char> result = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(result);
    // <ReturnType> result = sol.functionName(test parameters);
    for(auto i : result){
        cout << i << ' ';
    }
    return 0;
}