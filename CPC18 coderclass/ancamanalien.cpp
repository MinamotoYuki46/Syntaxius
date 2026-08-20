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

void dfs(int u, int p, const vii & grid, vi & tin, vi & tout, int & timer){
  tin[u] = timer++;

  for (int v : grid[u]){
    if (v == p) continue;

    dfs(v, u, grid, tin, tout, timer);
  }

  tout[u] = timer - 1;
}


bool is_ancestor(int u, int v, const vi &tin, const vi &tout){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}


void eval(int destroy, int check, const vi &tin, const vi &tout){
  if (destroy == 0 || destroy == check){
    cout << "TIDAK\n";
      return;
  }

  if (is_ancestor(destroy, check, tin, tout))
        cout << "TIDAK\n";
  else
      cout << "YA\n";
}

int32_t main(){
  //c_p_c();
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;

  vii adj(n);

  REP(i, n - 1){
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  vi tin(n), tout(n);
  int timer = 0;

  dfs(0, -1, adj, tin, tout, timer);

  int q; cin >> q;
  REP(i, q){
    int x, y; cin >> x >> y;
    x--, y--;

    eval(x, y, tin, tout);
  }
  return 0;
}
