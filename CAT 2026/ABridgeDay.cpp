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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

#define FOR(i, a, b)    for (int i = (a); i < (b); ++i)
#define REP(i, n)       FOR(i, 0, n)
#define FORD(i, a, b)   for (int i = (a); i >= (b); --i)
#define REPD(i, n)      FORD(i, n - 1, 0)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, l; cin >> n >> l;

    vi date_count (n + 1, 0);
    FOR(i, 1, n + 1) {
        int x; cin >> x;
        date_count[i] = x + date_count[i - 1];
    }

    // for(auto x: date_count){
    //     cout << x << ' ';
    // } cout << '\n';

    vi holidays (l);
    REP(i, l) {
        int d, m; cin >> d >> m;
        int x;
        if (m > 1){
            x = d + date_count[m - 1];
        }
        else{
            x = d;
        }
        holidays[i] = x;
        // cout << x << '\n';
    }

    bool flag = false;

    REP(i, l - 1){
        int date_bfr = holidays[i];
        int date_aft = holidays[i + 1];

        int mid = date_aft - date_bfr;

        if (mid == 2) flag = true;
    }

    if (flag) cout << "YA";
    else cout << "TIDAK";

    return 0;
}