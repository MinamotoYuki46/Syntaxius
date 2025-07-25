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

vii m(101, vi (101)), count_min(101, vi (101)), count_all(101, vi (101));
const int NEUE_MOD = 26101991;

void matrixChainMultiplication(const vi & dims){
    int n = dims.size() - 1;

    FOR(i, 1, n + 1){
        m[i][i] = 0;
        count_min[i][i] = 1;
        count_all[i][i] = 1;
    }

    FOR(l, 2, n + 1){
        FOR(i, 1, n - l + 2){
            int j = i + l - 1;
            m[i][j] = INF;
            count_min[i][j] = 0;
            count_all[i][j] = 0;

            FOR(k, i, j){
                int q = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];

                count_all[i][j] = (count_all[i][j] + count_all[i][k] * count_all[k + 1][j]) % NEUE_MOD;

                if (q < m[i][j]){
                    m[i][j] = q;
                    count_min[i][j] = (count_min[i][k] * count_min[k + 1][j]) % MOD;
                }
                else if (q == m[i][j]){
                    count_min[i][j] = (count_min[i][j] + (count_min[i][k] * count_min[k + 1][j]) % MOD) % MOD;
                }
            }
        }
    }
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vi matrix (n + 1);
    REP(i, n + 1) cin >> matrix[i];

    matrixChainMultiplication(matrix);

    int q; cin >> q;

    if (q == 1) cout << m[1][n];
    else if (q == 2) cout << count_min[1][n];
    else if (q == 3) cout << count_all[1][n];

    return 0;
}