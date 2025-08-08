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

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    vi cages(m + 1, 0), pref_pos (m + 1, 0), pref_val (m + 1, 0);

    REP(i, n){
        int x; cin >> x;
        cages[x]++;
    }

    FOR(i, 1, m + 1){
        pref_pos[i] += pref_pos[i - 1] + cages[i];
        pref_val[i] += pref_val[i - 1] + cages[i] * i;
    }

    // REP(i, m + 1) cout << pref_pos[i] << ' ';
    // cout << '\n';

    // REP(i, m + 1) cout << pref_val[i] << ' ';
    // cout << '\n';

    int ans = -1, res = -1, idx = -1;

    FOR(i, 1, m + 1){
        if (cages[i] != 0) continue;

        res = pref_val[m] - pref_val[i] - (n - pref_pos[i]) * i + (pref_pos[i] * i) - pref_val[i];
        // cout << res << '\n';
        if (res > ans){
            ans = res;
            idx = i;
        }
    }

    cout << idx;

    return 0;
}