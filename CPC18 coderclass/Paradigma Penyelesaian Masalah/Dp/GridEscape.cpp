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
#define vb              vector<bool>
#define vbb             vector<vb>
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define trailz(x)       __builtin_ctzll(x)
#define leadz(x)        __builtin_clzll(x)
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int32_t main(){
  //c_p_c();
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int r, c, n; cin >> r >> c >> n;

  vii grid(r, vi (c, 0));
  vii dp(r, vi (c, 0));

  REP(i, n){
    int u, v; cin >> u >> v;
    grid[--u][--v] = 1;
  }

  dp[0][0] = 1;

  REP(i, r) REP(j, c){
    if (grid[i][j] || (i == 0 && j == 0)) continue;

    if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
    if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
  }

  cout << dp[r - 1][c - 1];

  return 0;
}
