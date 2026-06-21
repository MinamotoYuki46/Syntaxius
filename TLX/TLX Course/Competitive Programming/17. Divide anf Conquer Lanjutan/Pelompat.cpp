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

const int H = 100;

struct Matrix {
    int a[H][H];

    Matrix(bool ident = false) {
        memset(a, 0, sizeof(a));

        if (ident) {
            REP(i, H) {
                a[i][i] = 1;
            }
        }
    }

    Matrix operator*(const Matrix& o) const {
        Matrix res;

        REP(i, H) REP(k, H) {
            if (!a[i][k]) continue;
            REP(j, H) {
                res.a[i][j] += a[i][k] * o.a[k][j];
                res.a[i][j] %= MOD;
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

int binexp(int a, int e, int mod = MOD) {
    int res = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vi heigth (n + 1);
    vi cnt (101);

    FOR(i, 1, n + 1){
        cin >> heigth[i];
        cnt[heigth[i]]++;
    }

    Matrix T;
    FOR(a, 1, 101) FOR(b, a, 101){
        T.a[b - 1][a - 1] = cnt[b];
    }

    vector<Matrix> pw(21);

    pw[0] = T;

    FOR(i, 1, 21) {
        pw[i] = pw[i - 1] * pw[i - 1];
    }


    w(q){
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            cout << (x == y) << '\n';
            continue;
        }

        int h_x = heigth[x] - 1;
        int h_y = heigth[y] - 1;

        vi vec(H);

        vec[h_x] = 1;

        REP(i, 21) {
            if (z & (1LL << i)) {

                vi nxt(H);

                REP(r, H) {
                    if (!vec[r]) continue;

                    REP(c, H) {
                        nxt[c] += vec[r] * pw[i].a[c][r];
                        nxt[c] %= MOD;
                    }
                }

                vec = nxt;
            }
        }


        int ans = vec[h_y];

        ans = ans * binexp(cnt[h_y + 1], MOD - 2) % MOD;

        cout << ans << '\n';
    }



    return 0;
}