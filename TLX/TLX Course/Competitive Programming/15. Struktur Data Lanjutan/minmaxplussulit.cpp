#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
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

#define MOD             1000000007;
const int INF = 1e18;
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



void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct Node {
    int max_1, max_2, max_c;
    int min_1, min_2, min_c;
    int sum, lazy_add;

    Node() : 
        max_1(-INF),
        max_2(-INF),
        max_c(0),
        min_1(INF),
        min_2(INF),
        min_c(0),
        sum(0),
        lazy_add(0) {}
};

vector<Node> tree;

void merge(Node& parent, const Node& l, const Node& r){
    parent.sum = l.sum + r.sum;

    if (l.max_1 > r.max_1){
        parent.max_1 = l.max_1;
        parent.max_c = l.max_c;
        parent.max_2 = max(l.max_2, r.max_1);
    } else if (l.max_1 < r.max_1){
        parent.max_1 = r.max_1;
        parent.max_c = r.max_c;
        parent.max_2 = max(r.max_2, l.max_1);
    } else {
        parent.max_1 = l.max_1;
        parent.max_c = l.max_c + r.max_c;
        parent.max_2 = max(l.max_2, r.max_2);
    }

    if (l.min_1 < r.min_1){
        parent.min_1 = l.min_1;
        parent.min_c = l.min_c;
        parent.min_2 = min(l.min_2, r.min_1);
    } else if (l.min_1 > r.min_1){
        parent.min_1 = r.min_1;
        parent.min_c = r.min_c;
        parent.min_2 = min(r.min_2, l.min_1);
    } else {
        parent.min_1 = l.min_1;
        parent.min_c = l.min_c + r.min_c;
        parent.min_2 = min(l.min_2, r.min_2);
    }
}

void add(int idx, int tl, int tr, int v){
    if (v == 0) return;

    tree[idx].sum += v * (tr -tl +1);
    tree[idx].max_1 += v;
    if (tree[idx].max_2 != -INF) tree[idx].max_2 += v;
    tree[idx].min_1 += v;
    if (tree[idx].min_2 != INF) tree[idx].min_2 += v;
    tree[idx].lazy_add += v;
}


void chmin(int idx, int v){
    if (v >= tree[idx].max_1) return;

    int prev_max = tree[idx].max_1;
    tree[idx].sum -= (prev_max - v) * tree[idx].max_c;
    tree[idx].max_1 = v;

    if (tree[idx].min_1 == prev_max) tree[idx].min_1 = v;

    if (tree[idx].min_2 == prev_max) tree[idx].min_2 = v;
}

void chmax(int idx, int v){
    if (v <= tree[idx].min_1) return;

    int prev_min = tree[idx].min_1;
    tree[idx].sum -= (prev_min - v) * tree[idx].min_c;
    tree[idx].min_1 = v;

    if (tree[idx].max_1 == prev_min) tree[idx].max_1 = v;

    if (tree[idx].max_2 == prev_min) tree[idx].max_2 = v;
}

void push(int idx, int tl, int tr){
    if (tl == tr) return;

    int tm = (tl + tr) / 2;

    add(idx * 2, tl, tm, tree[idx].lazy_add);
    add(idx * 2 + 1, tm + 1, tr, tree[idx].lazy_add);
    tree[idx].lazy_add = 0;

    chmin(idx * 2, tree[idx].max_1);
    chmin(idx * 2 + 1, tree[idx].max_1);
    
    chmax(idx * 2, tree[idx].min_1);
    chmax(idx * 2 + 1, tree[idx].min_1);
}

void build(int idx, int tl, int tr){
    if (tl == tr){
        tree[idx].max_1 = 0;
        tree[idx].max_2 = -INF;
        tree[idx].max_c = 1;
        tree[idx].min_1 = 0;
        tree[idx].min_2 = INF;
        tree[idx].min_c = 1;
        tree[idx].sum = 0;
        tree[idx].lazy_add = 0;
    }
    else {
        int tm = (tl + tr) / 2;
        build(idx * 2, tl, tm);
        build(idx * 2 + 1, tm + 1, tr);
        merge(tree[idx], tree[idx * 2], tree[idx * 2 + 1]);
    }
}

void range_add(int idx, int tl, int tr, int l, int r, int v) {
    if (l > r) return;
    if (l == tl && r == tr){
        add(idx, tl, tr, v);
        return;
    }
    push(idx, tl, tr);
    int tm = (tl + tr) / 2;
    range_add(idx * 2, tl, tm, l, min(r, tm), v);
    range_add(idx * 2 + 1, tm + 1, tr, max(l, tm + 1), r, v);
    merge(tree[idx], tree[idx * 2], tree[idx * 2 + 1]);
}

void range_chmin(int idx, int tl, int tr, int l, int r, int v) {
    if (l > r) return;
    if (v >= tree[idx].max_1) return;

    if (l == tl && r == tr && v > tree[idx].max_2){
        chmin(idx, v);
        return;
    }

    push(idx, tl, tr);
    int tm = (tl + tr) / 2;
    range_chmin(idx * 2, tl, tm, l, min(r, tm), v);
    range_chmin(idx * 2 + 1, tm + 1, tr, max(l, tm + 1), r, v);
    merge(tree[idx], tree[idx * 2], tree[idx * 2 + 1]);
}

void range_chmax(int idx, int tl, int tr, int l, int r, int v) {
    if (l > r) return;
    if (v <= tree[idx].min_1) return;

    if (l == tl && r == tr && v < tree[idx].min_2){
        chmax(idx, v);
        return;
    }

    push(idx, tl, tr);
    int tm = (tl + tr) / 2;
    range_chmax(idx * 2, tl, tm, l, min(r, tm), v);
    range_chmax(idx * 2 + 1, tm + 1, tr, max(l, tm + 1), r, v);
    merge(tree[idx], tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int pos){
    if (l == r) return tree[idx].max_1;
    push(idx, l, r);
    int mid = (l + r) / 2;
    if (pos <= mid) return query(idx * 2, l, mid, pos);
    else return query(idx * 2 + 1, mid + 1, r, pos);
}

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    int opt, l, r, v;
    tree.resize(4 * n);
    build(1, 1, n);

    while(q--){
        cin >> opt >> l >> r >> v;
        
        if (opt == 1) range_add(1, 1, n, l, r, v);
        else if (opt == 2) range_chmax(1, 1, n, l, r, v);
        else range_chmin(1, 1, n, l, r, v);

        // FOR(i, 1, n + 1) cout << query(1, 1, n, i) << ' ';
        // cout << '\n';
    }

    FOR(i, 1, n + 1) cout << query(1, 1, n, i) << ' ';
    cout << '\n';

    return 0;
}