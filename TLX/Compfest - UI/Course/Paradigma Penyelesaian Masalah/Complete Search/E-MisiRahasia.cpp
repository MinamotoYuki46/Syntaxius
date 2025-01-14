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
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x)          (x).begin(), (x).end()

#define mod             1000000007
#define inf             1e18
#define eps             1e-9

#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
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

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vii adj(n, vi(n, 0));

    REP(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x][y] = adj[y][x] = 1;
    }

    if (m == 0) {
        cout << 1 << '\n';
        return 0;
    }

    int ans = 1;

    FOR(mask, 1, 1 << n) {
        vector<int> subset;
        bool is_clique = true;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(i);
            }
        }

        REP(i, subset.size()) {
            FOR(j, i + 1, subset.size()) {
                if (!adj[subset[i]][subset[j]]) {
                    is_clique = false;
                    break;
                }
            }
            if (!is_clique) break;
        }

        if (is_clique) {
            ans = max(ans, (int)subset.size());
        }
    }

    cout << ans << '\n';
    return 0;
}