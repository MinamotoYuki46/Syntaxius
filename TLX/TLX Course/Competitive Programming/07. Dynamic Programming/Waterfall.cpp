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
#define pqs             priority_queue<int, vi, greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x)          (x).begin(), (x).end()

#define MOD             1000000007
#define INF             1e18
#define EPS             1e-9
#define DEG_TO_RAD      0.0174532925199432957692
#define RAD_TO_DEG      57.2957795130823208768
#define PI              3.14159265358979323846
#define E               2.71828182845904523536

#define ps(x,y)         fixed << setprecision(y) << x
#define mk(arr,n,type)  type *arr = new type[n];
#define w(x)            int x; cin >> x; while (x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

#define FOR(i, a, b)    for (int i = (a); i < (b); ++i)
#define REP(i, n)       FOR(i, 0, n)
#define FORD(i, a, b)   for (int i = (a); i >= (b); --i)
#define REPD(i, n)      FORD(i, n - 1, 0)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int v, h, n; 
vii grid;
vii dp;

int dfs(int r, int c){
    if (r > v || c < 1 || c > h) return 0;
    if (dp[r][c] == -2) return -1;
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = -2;

    if(!grid[r + 1][c]) return dp[r][c] = dfs(r + 1, c);

    int left = dfs(r, c - 1);
    int right = dfs(r, c + 1);
    int res = left + right + 1;
    dp[r][c] = -1;
    return res;   
}


int maxCollision(vii & grid){
    int res = 0;

    FOR(i, 1, h + 1){
        res = max(res, dfs(0, i));
    }

    return res;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v >> h >> n;

    grid.assign(v + 2, vi(h + 2, 0));
    dp.assign(v + 2, vi (h + 2, -1));

    REP(i, n){
        int v1, h1, v2, h2;
        cin >> v1 >> h1 >> v2 >> h2;
        FOR(i, v1, v2 + 1){
            FOR(j, h1, h2 + 1){
                grid[i][j] = 1;
            }
        }
    }

    cout << maxCollision(grid);

    // cout << '\n';
    // REP(i, v + 2){
    //     REP(j, h + 2){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}