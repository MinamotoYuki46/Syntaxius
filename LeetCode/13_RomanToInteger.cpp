// LeetCode Problem: Roman to Integer
// Problem URL: https://leetcode.com/problems/roman-to-integer/
// Difficulty: Easy
// Solution Date: 26 October 2024

// Problem Statement:
// Given a roman numeral, convert it to an integer.


// Approach:
// Explain approach here.

// Complexity Analysis:
// Time Complexity: O(n) - to traverse the string roman number
// Space Complexity: O(...) - Explain

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            if      (s[i] == 'M') sum += 1000;

            else if (s[i] == 'D') sum += 500;

            else if (s[i] == 'C') {
                if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    sum -= 100;
                } 
                else {
                    sum += 100;
                }
            } 
            
            else if (s[i] == 'L') sum += 50;
            
            else if (s[i] == 'X') {
                if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    sum -= 10;
                } 
                else {
                    sum += 10;
                }
            } else if (s[i] == 'V') sum += 5;
            
            else if (s[i] == 'I') {
                if (i + 1 < s.size() && (s[i + 1] == 'X' || s[i + 1] == 'V')) {
                    sum -= 1;
                } 
                else {
                    sum += 1;
                }
            }

        }
        return sum;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    string rom = "MCMXCIV";
    int result = sol.romanToInt(rom);
    cout << "Result: " << result << endl;
    return 0;
}