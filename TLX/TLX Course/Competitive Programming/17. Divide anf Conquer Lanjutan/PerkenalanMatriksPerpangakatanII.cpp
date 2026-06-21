#include <bits/stdc++.h>
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
    int arr[3][3];

    Matrix(bool ident = false) {
        memset(arr, 0, sizeof(arr));

        if (ident) {
            for (int i = 0; i < 3; i++) {
                arr[i][i] = 1;
            }
        }
    }

    Matrix operator*(const Matrix& o) const {
        Matrix res;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    res.arr[i][j] += arr[i][k] * o.arr[k][j];
                }
            }
        }

        return res;
    }
};

Matrix fpow(Matrix base, int exp) {
    Matrix res(true);

    while (exp) {
        if (exp & 1) {
            res = res * base;
        }

        base = base * base;
        exp >>= 1;
    }

    return res;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    int f[6] = {1, 1, 2, 3, 4, 5};
    int k = n / 6, r = n % 6;

    Matrix A;
    A.arr[0][0] = 1;
    A.arr[0][1] = 1;
    A.arr[0][2] = 6;
    A.arr[1][1] = 1;
    A.arr[1][2] = 6;
    A.arr[2][2] = 1;

    Matrix P = fpow(A, k);

    int state[3] = {
        f[r],
        r,
        1
    };

    int ans = 0;

    REP(i, 3){
        ans += P.arr[0][i] * state[i];
    }

    cout << ans;


    return 0;
}