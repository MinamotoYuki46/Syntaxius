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

int cross_prod(const pii & a, const pii & b, const pii & c){
	return (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff);
}

bool segment(const pii & a, const pii & b, const pii & c){
	if (cross_prod(a, b, c) != 0) return false;

	return min(a.ff, b.ff) <= c.ff && c.ff <= max(a.ff, b.ff) &&  min(a.ss, b.ss) <= c.ss && c.ss <= max(a.ss, b.ss);
}

bool intersect(const pii & a, const pii & b, const pii & c, const pii & d){
	int p1 = cross_prod(a, b, c), p2 = cross_prod(a, b, d), p3 = cross_prod(c, d, a), p4 = cross_prod(c, d, b);

	if (p1 == 0 && segment(a, b, c) || p2 == 0  && segment(a, b, d) || p3 == 0 && segment(c, d, a) || p4 == 0 && segment(c, d, b)) return true;

	return ((p1 > 0 && p2 < 0) || (p1 < 0 && p2 > 0)) && ((p3 > 0 && p4 < 0) || (p3 < 0 && p4 > 0));
}

int32_t main(){
	//c_p_c();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	w(tc){
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		int x_min = min(x1, x2), x_max = max(x1, x2);
		int y_min = min(y1, y2), y_max = max(y1, y2);

		pii a {x_min, y_min}, b {x_min, y_max}, c {x_max, y_max}, d {x_max, y_min}, s {x3, y3}, e {x4, y4};

		bool flag = intersect(s, e, a, b) || intersect(s, e, b, c) || intersect(s, e, c, d) || intersect(s, e, d, a);

		cout << (flag?"YA":"TIDAK") << '\n';
	}

	return 0;
}