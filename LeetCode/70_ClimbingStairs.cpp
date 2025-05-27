#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if (n == 2) return 2;
       
       vector<int> stair(n);
       stair[0] = 1;
       stair[1] = 2;
       for(int i = 2; i < n; ++i){
        stair[i] = stair[i - 1] + stair[i - 2];
       }

       return stair[n - 1]; 
    }
};

//optional for testing
int main(){
    Solution sol;
    int n;
    cin >> n;
    int ans = sol.climbStairs(n);
    cout << ans;
    
}