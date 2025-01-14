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
#define vii             vector<vector<int>>
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

void LCS(string x, string y){
    int n = x.size(), m = y.size();

    if (n == 0 || m == 0) return;

    vii dp (n + 1, vi(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = max(dp[i][j] ,dp[i - 1][j - 1] + 1);
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    string res;

    int i = n, j = m;
    while (i && j) {
        if (x[i-1] == y[j-1]) {
            res += x[i-1];
            i--, j--;
        }
        else if (dp[i][j-1] >= dp[i-1][j]) {
            j--;
        }
        else i--;
    }
    reverse(res.begin(), res.end());
    
    cout << res << endl;

};

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;

    LCS(a, b);

    return 0;
}