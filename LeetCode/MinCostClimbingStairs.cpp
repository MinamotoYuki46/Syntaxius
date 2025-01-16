#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        if(sz == 2) return min(cost[0], cost[1]); 
        vector<int> dp(sz + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i <= sz; ++i){
            if(i < sz) dp[i] = min(cost[i] + dp[i - 1], cost[i] + dp[i - 2]);
            if(i == sz) dp[i] = min(dp[i - 1], dp[i - 2]);
        }

        return dp[sz];
    }
};

int main(){
    class Solution sol;
    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; ++i) cin >> cost[i]; 
    int ans = sol.minCostClimbingStairs(cost);
    cout <<ans;
    return 0;
}