// LeetCode Problem: Jewels and Stones
// Problem URL: https://leetcode.com/problems/jewels-and-stones/
// Difficulty: Easy
// Solution Date: 29 October 2024

// Problem Statement:
// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. 
// Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

// Approach:
// pretty easy :D. store the jewels into map or set, then check if the stone in the jewel or not

// Complexity Analysis:
// Time Complexity: O(n + m) - n to make jewels into sets, m for traversing stone
// Space Complexity: O(n) - n the set of jewels

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;

        set<char> jwl (jewels.begin(), jewels.end());

        for(int i = 0; i < stones.length(); i++){
            if(jwl.find(stones[i]) != jwl.end())
                res++;
        }
        return res;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    string jewels = "aA", stones = "aAAbbbb";


    int result = sol.numJewelsInStones(jewels, stones);
    cout << "Result: " << result << endl;
    return 0;
}