// LeetCode Problem:  Best Time to Buy and Sell Stock
// Problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Solution Date: 28 july 2024

// Problem Statement:
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Approach:
// greedy here. assume you buy current. Buy when you find today is cheaper than yesterday and tomorrow. Sell when tomorrow the price goes down.
// first find the lowest prices, and each itertation will try to calculate the current profit and then if it is optimal for final profit, let it in.

// Complexity Analysis:
// Time Complexity: O(n) - to traverse
// Space Complexity: O(1) - to store the profit only

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = INT_MAX, curProfit;

        for(int i = 0; i < prices.size(); i++){
            if (prices[i] < minPrice) minPrice = prices[i]; 

            curProfit = prices[i] - minPrice;

            if(curProfit > profit) profit = curProfit;
        }
        return profit;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    vector <int> prices = {7,1,5,3,6,4};
    int result = sol.maxProfit(prices);
    cout << "Result: " << result << endl;
    return 0;
}