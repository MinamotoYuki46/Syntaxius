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
#define vb              vector<bool>
#define vbb             vector<vb>
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

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dist_segment(double px, double py, double x1, double y1, double x2, double y2){
    double vx = x2 - x1, vy = y2- y1;
    double wx = px - x1, wy = py - y1;
    double d2 = vx * vx + vy * vy;

    if (d2 == 0.0) return dist(px, py, x1, y1);

    double t = (wx * vx + wy * vy) / d2;
    if (t < 0.0) t = 0.0;
    if (t > 1.0) t = 1.0;

    double dx = x1 + t * vx;
    double dy = y1 + t * vy;

    return dist(px, py, dx, dy);
}

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; double xp, yp;
    cin >> n >> xp >> yp;

    vector<pii> p (n);

    REP(i, n) cin >> p[i].ff >> p[i].ss;

    double d_max = 0.0;
    for(auto [x, y] : p){
        d_max = max(d_max, dist(xp, yp, x, y));
    } 

    double d_min = INF;
    REP(i, n){
        int j = (i + 1) % n;
        d_min = min(d_min, dist_segment(xp, yp, p[i].ff, p[i].ss, p[j].ff, p[j].ss));
    }

    double area = PI * (d_max * d_max - d_min * d_min);
    cout << ps(area, 8);

    return 0;
}