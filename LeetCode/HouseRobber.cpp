#include <bits/stdc++.h>
using namespace std;

//  kayaknya untuk memori aku kalah deh
//  yang penting acc 
//  ~Galih

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums[0];
        vector<int> dp (sz);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int maxs = max(dp[0], dp[1]);
        for(int i = 2; i < sz; ++i){
            for(int j = 0; j < i - 1; ++j){
                dp[i] = max(dp[j] + nums[i], dp[i]);
            }
            maxs = max(dp[i], maxs);
        }

        return maxs;
    }
};

//optional for testing
int main(){
    class Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i]; 
    int ans = sol. rob(nums);
    cout <<ans;
    return 0;
}