// LeetCode Problem: Evaluating Reverse Polish Notaion
// Problem URL: https://leetcode.com/problems/evaluate-reverse-polish-notation
// Difficulty: Medium
// Solution Date: 24 March 2025

// Problem Statement:
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

//     The valid operators are '+', '-', '*', and '/'.
//     Each operand may be an integer or another expression.
//     The division between two integers always truncates toward zero.
//     There will not be any division by zero.
//     The input represents a valid arithmetic expression in a reverse polish notation.
//     The answer and all the intermediate calculations can be represented in a 32-bit integer.


// Constraint
// 1 <= tokens.length <= 10^4
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].


// Approach:
// using shuting yard algorithm. first initialize the stack to store the tokens, then if the operand exist, take the last 2 element and do operation and store the result back to the top

// Complexity Analysis:
// Time Complexity: O(n) - to iterate the tokens
// Space Complexity: O(n) - to store the res into the stack 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;

            for(const auto& i: tokens){
                if (i == "+" || 
                    i == "-" ||
                    i == "*" ||
                    i == "/"){
                        int b = st.top(); st.pop();
                        int a = st.top(); st.pop();

                        if (i == "+") st.push(a + b);
                        else if (i == "-") st.push(a - b);
                        else if (i == "*") st.push(a * b);
                        else{
                            double div = (double) a / b;
                            st.push(div < 0? (int) ceil(div) : (int) floor(div));
                        }
                    }
                else{
                    st.push(stoi(i));
                }
            }

            return st.top();
        }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}; 
    int result = sol.evalRPN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}