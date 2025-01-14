#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int palindromeWithLCS(string str){
    int n = str.size();
    string rev_str = str;

    reverse(rev_str.begin(), rev_str.end());

    vii dp (n + 1, vi (n + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (str[i - 1] == rev_str[j - 1]) dp[i][j] = dp[i -1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return n - dp[n][n];
};

int minPalindrome(string str) {
    int n = str.size();
    vii dp(n + 1, vi(n + 1, 0));

    for (int t = 2; t <= n; t++) {
        for (int i = 1, j = t ; j <= n; i++, j++) {
            if (str[i - 1] == str[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for (int j = 0; j <= n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return dp[1][n];
};

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;

    cout << "With LCS\n" << palindromeWithLCS(str) << endl;
    cout << "Without LCS \n" << minPalindrome(str) << endl;

    return 0;
}