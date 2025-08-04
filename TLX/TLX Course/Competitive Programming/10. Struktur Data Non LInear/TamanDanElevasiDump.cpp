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

struct DSU {
    vi parent, rank, sz;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        sz.assign(n, 1);
        iota(all(parent), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;

        if (rank[rx] < rank[ry]) swap(rx, ry);

        parent[ry] = rx;
        sz[rx] += sz[ry];

        if (rank[rx] == rank[ry])
            rank[rx]++;
    }

    bool check(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    DSU dsu(n * m);

    vii a (n, vi (m));
    vbb visited (n, vb (m, 0));
    map<int, vector<pii>, greater<>> height;
    set<int, greater<>> nums;
    vii count (n, vi (m));
    int add = 0;
    vector<pii> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    REP(i, n) REP(j, m){
        cin >> a[i][j];
        height[a[i][j]].pb({i, j});
        nums.insert(a[i][j]);
        count[i][j] = add++;
    }

    int ans = 0, res = 0;

    for(auto val: nums){
        ans = max(ans, res);
        int sum = 0;

        REP(i, height[val].size()){
            auto [x, y] = height[val][i];
            int cnt = 0;

            for(auto &[dx, dy]: dir){
                int _x = x + dx, _y = y + dy;

                if (_x < 0 || _x >= n || _y < 0 || _y >= m) continue;

                int neighbour = a[_x][_y];
                if (a[_x][_y] >= val){
                    cnt++;
                    dsu.unite(count[_x][_y], count[x][y]);
                }
            }
            if (cnt > 0) res -= (cnt - 1);
            else res++;
        }
    }

    cout << (ans == 0? 1: ans);
    return 0;
}