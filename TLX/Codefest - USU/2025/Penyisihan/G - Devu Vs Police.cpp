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

int eulerPhi(int n){
    int res = n;

    for(int p = 2; p * p <= n; p++){
        if (n % p == 0){
            while (n % p == 0){
                n /= p;
            }
            res -= res / p;
        }
    }

    if (n > 1) res -= res / n;

    return res;
}

int powmod(int base, int exp, int mod) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n1, k1, n2, k2, n; 
    
    w(tc) {
        cin >> n1 >> k1 >> n2 >> k2 >> n;

        if (k1 == 0 || (n2 == 0 && k2 != 0)) {
            cout << 1LL % n << '\n';
            continue;
        }
        if (n2 == 1 || k2 == 0) {
            cout << powmod(n1, k1, n) << '\n';
            continue;
        }
        if (n1 == 0 || n1 % n == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (k2 == 1) {
            cout << powmod(n1, 1LL * k1 * n2, n) << '\n';
            continue;
        }
        
        int phi = eulerPhi(n);
        int e = powmod(n2, k2, phi);
        cout << powmod(powmod(n1, k1, n), e, n) << '\n';
    }
    return 0;
}