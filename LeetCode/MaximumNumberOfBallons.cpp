// LeetCode Problem: Maximum Number of ballolns
// Problem URL: https://leetcode.com/problems/maximum-number-of-balloons/description/
// Difficulty: Easy
// Solution Date: 30 October 2024

// Problem Statement:
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

// Approach:
// map all char, then counting letter to make "balloon". If we can, increase res and decrease the map for the "ballon"

// Complexity Analysis:
// Time Complexity: O(n) - inserting to mci
// Space Complexity: O(1) - storing 26 alphabet

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mci;
        int res = 0;

        for(auto i: text){
            mci[i]++;
        }

        while(true){
            if (mci['b'] >= 1 && mci['a'] >= 1 && mci['l'] >= 2 && mci['o'] >= 2  && mci['n'] >= 1){
                res++;
                mci['b']--, mci['a']--, mci['l'] -= 2, mci['o'] -= 2, mci['n']--;
            }
            else{
                break;
            }
        }

        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    string text = "nlaebolko";

    int result = sol.maxNumberOfBalloons(text);
    cout << "Result: " << result << endl;
    return 0;
}