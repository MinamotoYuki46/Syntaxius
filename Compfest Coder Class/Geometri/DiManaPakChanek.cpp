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
#define vii             vector<vi>
#define vbb             vector<vb>
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

bool check(vector<pii> &polygon, pii &pos) {
    int size = polygon.size();
    bool inside = false;

    for (int i = 0, j = size - 1; i < size; j = i++) {
        int xi = polygon[i].ff, yi = polygon[i].ss;
        int xj = polygon[j].ff, yj = polygon[j].ss;

        bool intersect = ((yi > pos.ss) != (yj > pos.ss)) &&
                         (pos.ff < (double)(xj - xi) * (pos.ss - yi) / (double)(yj - yi) + xi);

        if (intersect) inside = !inside;
    }
    return inside;
}


double dist(pii &a, pii &b, pii &p){
    double x1 = a.ff, y1 = a.ss;
    double x2 = b.ff, y2 = b.ss;
    double x0 = p.ff, y0 = p.ss;

    double dx = x2 - x1, dy = y2 - y1;
    double seg_len2 = dx*dx + dy*dy;

    if (seg_len2 == 0.0) {
        return hypot(x0 - x1, y0 - y1);
    }

    double t = ((x0 - x1)*dx + (y0 - y1)*dy) / seg_len2;

    if (t < 0.0) {
        return hypot(x0 - x1, y0 - y1);
    } else if (t > 1.0) {
        return hypot(x0 - x2, y0 - y2);
    } else {
        double projx = x1 + t*dx;
        double projy = y1 + t*dy;
        return hypot(x0 - projx, y0 - projy);
    }
}



int32_t main(){
	//c_p_c();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<pii> point (n);

	REP(i, n) cin >> point[i].ff >> point[i].ss;

	pii pos; cin >> pos.ff >> pos.ss;

	double ans = 1e5;
	if(!check(point, pos)){
		cout << -1;
		return 0;
	}
	else {
		REP(i, n){
			double cur_ans = dist(point[i % n], point[ (i + 1) % n], pos);
			ans = min(ans, cur_ans);
		}
	}

	cout << ps(ans, 6);

	return 0;
}