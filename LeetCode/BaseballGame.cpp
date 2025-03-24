// LeetCode Problem: Baseball Game
// Problem URL: https://leetcode.com/problems/baseball-game
// Difficulty: Easy
// Solution Date: 24 March 2025

// Problem Statement:
//You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
// You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

// An integer x.
//     Record a new score of x.
// '+'.
//     Record a new score that is the sum of the previous two scores.
// 'D'.
//     Record a new score that is the double of the previous score.
// 'C'.
//     Invalidate the previous score, removing it from the record.

// Return the sum of all the scores on the record after applying all the operations.

// The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.


// Constraint
// 1 <= operations.length <= 1000
// operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
// For operation "+", there will always be at least two previous scores on the record.
// For operations "C" and "D", there will always be at least one previous score on the record.


// Approach:
// pretty ez tho, just follow the instruction, when to pop and push. we need to allocate since we need to take 2 last element of the stack

// Complexity Analysis:
// Time Complexity: O(n) - iteratin=g the oprations
// Space Complexity: O(1) - to store res and 2 last element

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int calPoints(vector<string>& operations) {
            stack<int> st;

            for(auto x: operations){
                if (x == "C"){
                    st.pop();
                }
                else if (x == "D"){
                    int a =st.top();
                    st.push(a*2);
                }
                else if (x == "+"){
                    int a = st.top();
                    st.pop();
                    int y= st.top();
                    st.push(a);
                    st.push(a+y);
                }
                else{
                    st.push(stoi(x));
                }
            }        
            int ans = 0;
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            return ans;
        }
    };

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    vector<string> test = {"5","2","C","D","+"};

    int result = sol.calPoints(test);
    cout << "Result: " << result << endl;
    return 0;
}