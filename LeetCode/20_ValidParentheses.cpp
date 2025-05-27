// LeetCode Problem:Valid Parentheses
// Problem URL: https://leetcode.com/problems/valid-parentheses
// Difficulty: Easy
// Solution Date: 24 March 2025

// Problem Statement:
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


// Constraint
//1 <= s.length <= 104
// s consists of parentheses only '()[]{}'

// Approach:
// easy, only perform pop when it match the close and open parentheses (using stack.top())

// Complexity Analysis:
// Time Complexity: O(n) - to iterate the string
// Space Complexity: O(n) - to store each char in the stack

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto i: s){
            if (i == '(' || i == '{' || i == '['){
                st.push(i);
            }
            else{
                if (st.empty() || 
                    (i == '}' && st.top() != '{') || 
                    (i == ')' && st.top() != '(') || 
                    (i == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    string test = "]";
    bool result = sol.isValid(test);
    cout << "Result: " << result << endl;
    return 0;
}