/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n, 0);
        stack<int> stk;

        for(int i = 0; i < n; i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int prev = stk.top();
                res[prev] = i - prev;
                stk.pop();
            }

            stk.push(i);
        }

        return res;
    }
};
// @lc code=end

