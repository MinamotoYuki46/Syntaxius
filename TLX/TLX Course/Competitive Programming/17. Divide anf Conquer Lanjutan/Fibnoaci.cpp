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

struct Matrix {
    int a[2][2];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        REP(i, 2) REP(j, 2) REP(k, 2)
            res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
        return res;
    }
};

Matrix matpow(Matrix base, int n) {
    Matrix res;
    res.a[0][0] = 1;
    res.a[1][1] = 1;

    while (n > 0) {
        if (n & 1) { 
            res = res * base;
        }
        base = base * base;
        n >>= 1;
    }

    return res;
}

int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;

    Matrix base;
    base.a[0][0] = 1;
    base.a[0][1] = 1;
    base.a[1][0] = 1;
    base.a[1][1] = 0;

    Matrix result = matpow(base, n - 1);
    return result.a[0][0];
}

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    cout << fibonacci(n);

    return 0;
}