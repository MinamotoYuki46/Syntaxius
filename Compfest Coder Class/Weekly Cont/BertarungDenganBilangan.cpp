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

#define NEUE_MOD 998244353;

int32_t main(){
	//c_p_c();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, max_fact = 0, ans = 1;
	vii freq (2, vi (2e6 + 1));
	
	cin >> n;
	vector<pii> prime_x (n);

	REP(i, n){
		cin >> prime_x[i].ff;
		max_fact = max(max_fact, prime_x[i].ff);
	}
	REP(i, n){
		cin >> prime_x[i].ss;
		freq[0][prime_x[i].ff] = prime_x[i].ss;
	}

	cin >> m;
	vector<pii> prime_y (m);

	REP(i, m){
		cin >> prime_y[i].ff;
		max_fact = max(max_fact, prime_y[i].ff);
	}
	REP(i, m){
		cin >> prime_y[i].ss;
		freq[1][prime_y[i].ff] = prime_y[i].ss;
	}

	REP(i, max_fact + 1){
		if (freq[0][i] < freq[1][i]){
			cout << 0;
			return 0;
		}

		if (freq[0][i] > freq[1][i]){
			ans = (ans << 1) % NEUE_MOD;
		}
	}

	cout << ans;

	return 0;
}