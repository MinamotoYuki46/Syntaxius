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

  double x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  double dx1 = x2 - x1, dy1 = y2 - y1;
  double dx2 = x4 - x3, dy2 = y4 - y3;

  double den = dx1 * dy2 - dy1 * dx2;

  if (den == 0){
    cout << "-1 -1";
    return 0;
  }

  double dx = x3 - x1;
  double dy = y3 - y1;

  double t = (dx * dy2 - dy * dx2) / den;
  double u = (dx * dy1 - dy * dx1) / den;

  if (t < 0 || t > 1 || u < 0 || u > 1) {
      cout << "-1 -1";
      return 0;
  }

  double x = x1 + t * dx1;
  double y = y1 + t * dy1;

  cout << ps(x, 10) << ' ' << ps(y, 10);
  return 0;
}
