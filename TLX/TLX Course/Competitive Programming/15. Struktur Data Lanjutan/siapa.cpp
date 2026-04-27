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

#define MOD             998244353
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

template<class T, int sz> struct segment_tree {
    const T no = 0, no_op = 0;
    T seg[2 * sz], lazy[2 * sz];

    T comb(T a, T b) { return (a + b) % MOD; }

    void push(int idx, int l, int r){
        seg[idx] += (r - l + 1) * lazy[idx] % MOD;
        if (seg[idx] >= MOD) seg[idx] -= MOD;

        if (l != r){
            lazy[2 * idx] += lazy[idx];
            if (lazy[2 * idx] >= MOD) lazy[2 * idx] -= MOD;
            lazy[2 * idx + 1] += lazy[idx];
            if (lazy[2 * idx + 1] >= MOD) lazy[2 * idx + 1] -= MOD;
        }
        lazy[idx] = no_op;
    };

    void pull(int idx){
        seg[idx] = comb(seg[2 * idx], seg[2 * idx + 1]);
    };

    void build() {
        FORD(i, sz - 1, 1) pull(i);
    };

    void update(int l, int r, T val, int idx = 1, int lx = 0, int rx = sz - 1){
        push(idx, lx, rx);
        if (r < lx || l > rx) return;
        if (l <= lx && rx <= r){
            lazy[idx] = val;
            push(idx, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        update(l, r, val, 2 * idx, lx, m);
        update(l, r, val, 2 * idx + 1, m + 1, rx);
        pull(idx);
    }

    T query(int l, int r, int idx = 1, int lx = 0, int rx = sz - 1){
        push(idx, lx, rx);
        if (r < lx || l > rx) return no;
        if (l <= lx && rx <= r) return seg[idx];

        int mid = (lx + rx) / 2;
        return comb(
            query(l, r, 2 * idx, lx, mid),
            query(l, r, 2 * idx + 1, mid + 1, rx)
        );
    }
};

segment_tree<int, 131072> seg_tree;
vi adj[100005];
pii children[100005];
bool vis[100005];
int par[100005];
int pos[100005];
int val[100005];

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    FOR(i, 1, n + 1){
        cin >> val[i];
        children[i] = {n + 1, -1};
    }

    FOR(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int position = 0;
    queue<int> q;
    q.push(1); vis[1] = true;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        position++;
        pos[cur] = position;

        seg_tree.update(position, position, val[cur]);
        if (cur != 1){
            children[par[cur]].ff = min(children[par[cur]].ff, position);
            children[par[cur]].ss = max(children[par[cur]].ss, position);
        }
        for(int nx : adj[cur]){
            if (!vis[nx]){
                vis[nx] = true;
                par[nx] = cur;
                q.push(nx);
            }
        }
    }

    w(queries){
        int op, x; cin >> op >> x;
        if (op == 1){
            int v = seg_tree.query(pos[x], pos[x]);
            seg_tree.update(children[x].ff, children[x].ss,v);
            if (x != 1) seg_tree.update(pos[par[x]], pos[par[x]], v);
        }
        else {
            int ans = seg_tree.query(children[x].ff, children[x].ss);
            if (x != 1){
                ans += seg_tree.query(pos[par[x]], pos[par[x]]);
                if (ans >= MOD) ans -= MOD;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}