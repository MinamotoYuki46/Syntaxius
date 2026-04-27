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

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MAXN = 200005;

int N, D, Q;
string S;

int seg[4 * MAXN], lazy[4 * MAXN];

void push(int node) {
    if (lazy[node] != 0) {
        seg[node*2] += lazy[node];
        seg[node*2+1] += lazy[node];
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
        lazy[node] = 0;
    }
}

void build(int node, int l, int r, vector<int> &a) {
    if (l == r) {
        seg[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node*2, l, mid, a);
    build(node*2+1, mid+1, r, a);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

void update(int node, int l, int r, int ql, int qr, int val) {
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        seg[node] += val;
        lazy[node] += val;
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    update(node*2, l, mid, ql, qr, val);
    update(node*2+1, mid+1, r, ql, qr, val);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

int query_first(int node, int l, int r, int k) {
    if (seg[node] <= k) return -1;
    if (l == r) return l;
    push(node);
    int mid = (l + r) >> 1;
    if (seg[node*2] > k)
        return query_first(node*2, l, mid, k);
    else
        return query_first(node*2+1, mid+1, r, k);
}


int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> D;
    cin >> S;
    S = " " + S;

    vi a(N+1, 0);

    int cur = 0;
    for (int i = 1; i <= N; i++) {
        if (S[i] == '1') cur++;
        if (i - D >= 1 && S[i-D] == '1') cur--;
        a[i] = cur;
    }

    build(1, 1, N, a);

    cin >> Q;
    while (Q--) {
        int t; cin >> t;

        if (t == 1) {
            int x; cin >> x;

            int delta = (S[x] == '0' ? 1 : -1);
            S[x] = (S[x] == '0' ? '1' : '0');

            int L = x;
            int R = min(N, x + D - 1);

            update(1, 1, N, L, R, delta);
        }
        else {
            int k; cin >> k;

            int ans = query_first(1, 1, N, k);
            cout << ans << '\n';
        }
    }

    return 0;
}