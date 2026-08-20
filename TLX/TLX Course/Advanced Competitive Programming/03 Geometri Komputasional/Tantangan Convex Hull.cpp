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

int cross_prod(const pii & a, const pii & b, const pii & c){
	return (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff);
}

bool cmp(const pii &a, const pii &b){
    if (a.ff != b.ff) return a.ff < b.ff;
    return a.ss < b.ss;
}

vector<pii> convex_hull(vector<pii> points){
    sort(all(points), cmp);

    int n = points.size();
    if (n <= 1) return points;

    vector<pii> lower, upper;

    REP(i, n){
        while(lower.size() >= 2 && cross_prod(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) < 0)
            lower.pop_back();
        lower.pb(points[i]);
    }

    REPD(i, n){
        while(upper.size() >= 2 && cross_prod(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) < 0)
            upper.pop_back();
        upper.pb(points[i]);
    }

    lower.pop_back();
    upper.pop_back();

    vector<pii> hull = lower;
    hull.insert(hull.end(), all(upper));
    return hull;
}

bool hull_contains_polygon(const vector<pii> &hull, const vector<pii> &poly){
    if (hull.size() < 3) return false;
    int m = hull.size();

    for (const auto [x ,y]: poly){
        bool ok = true;
        REP(i, m){
            int j = (i + 1) % m;

            if (cross_prod(hull[i], hull[j], {x, y}) < 0){
                ok = false;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m, n; cin >> m >> n;
    vector<pii> q(m), p(n);

    REP(i, m) cin >> q[i].ff >> q[i].ss;
    REP(i, n) cin >> p[i].ff >> p[i].ss;

    int layers = 0;
    vector<pii> rem = q;

    while(true){
        if (rem.size() < 3) break;

        vector<pii> hull = convex_hull(rem);
        if (hull.size() < 3) break;
        if (!hull_contains_polygon(hull, p)) break;

        set<pii> rmv;
        for(auto [x, y]: hull){
            rmv.insert({x, y});
        }

        vector<pii> nxt;
        nxt.reserve(rem.size());
        for (auto [x, y]: rem){
            if (rmv.count({x, y}) == 0) nxt.pb({x, y});
        }

        rem.swap(nxt);
        layers++;
    }

    cout << layers;

    return 0;
}
