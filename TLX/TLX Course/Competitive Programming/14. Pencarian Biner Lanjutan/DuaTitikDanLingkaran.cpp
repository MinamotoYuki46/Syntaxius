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

double x_a, y_a, x_b, y_b, x_0, y_0, rad;

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

double f(double p){
	double x_p = x_0 + rad * cos(p);
	double y_p = y_0 + rad * sin(p);

	return dist(x_a - x_p, y_a - y_p) + dist(x_b - x_p, y_b - y_p);
}

int32_t main(){
	//c_p_c();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x_a >> y_a >> x_b >> y_b >> x_0 >> y_0 >> rad;

	double l = atan2(y_a - y_0, x_a - x_0), r = atan2(y_b - y_0, x_b - x_0);

	if (l > r) swap(l, r);
	if (r - l > PI){
		l += 2 * PI;
		swap(l, r);
	}

	while(r - l >= EPS){
		double m1 = l + (r - l)/3, m2 = r - (r - l)/3;
		double val1 = f(m1), val2 = f(m2);

		if (val1 >= val2) l = m1;
		else r = m2;
	}

	cout << ps(f((l + r) / 2), 9);

	return 0;
}