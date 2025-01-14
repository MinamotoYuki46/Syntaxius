#include <bits/stdc++.h>
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

vii matrixMultiply(const vii & a, const vii & b){
    int n = a.size();
    vii c(n, vi(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }

    return c;
}

int solve(int target, vi& coins){
    int n = coins.size();
    vi dp(35, 0);
    vii ans(35, vi(35, 0)), hit(35, vi(35, 0));

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        hit[32 - coins[i]][31]++;
    }

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            if (i == j) ans[i][j] = 1;
            if (i -1 == j && j != 31) hit[i][j] = 1;
        }
    }

    for(int i = 1; i <= 32; i++){
        for(int j = 0; j < n; j++){
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
        }
    }

    if (target > 32){
        target -= 32;

        while (target > 0){
            if (target % 2 == 1) {
                ans = matrixMultiply(ans, hit);
            }
            hit = matrixMultiply(hit, hit);
            target >>= 1;
        }

        int count = 0;
        for(int i = 1; i <= 32; i++){
            count = (count + dp[i] * ans[i - 1][31]) % mod;
        }
        return count;
    }

    else return dp[target];
}

int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(tc){
        int n, x;
        cin >> n >> x;
        vi coins(n);

        for(int i = 0; i < n; i++){
            cin >> coins[i];
        }

        cout << solve(x, coins) << endl;
    }

    return 0;
}
