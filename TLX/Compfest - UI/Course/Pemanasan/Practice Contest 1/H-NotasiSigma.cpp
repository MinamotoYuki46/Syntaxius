#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define ull             unsigned long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
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


#define MAXN 100000


vector<ull> factorial(MAXN + 1, 1);
vector<ull> inv_factorial(MAXN + 1, 1);

inline ull mod_exp(ull x, ull y){
    ull res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void precompute_factorials(int max_n) {
    for (int i = 2; i <= max_n; ++i) {
        factorial[i] = factorial[i - 1] * i % mod;
    }
    inv_factorial[max_n] = mod_exp(factorial[max_n], mod - 2);  
    for (int i = max_n - 1; i >= 0; --i) {
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % mod;
    }
}

inline ull nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return factorial[n] * inv_factorial[r] % mod * inv_factorial[n - r] % mod;
}

inline ull comb(int n, int r, int k, int j) {
    if (j > k || j > n || k - j > r) return 0;
    return nCr(n, j) * nCr(r, k - j) % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    precompute_factorials(MAXN);

    ull sum = 0;
    w(t) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int j = 0; j <= k; ++j) {
            sum = (sum + comb(n, m, k, j)) % mod;
        }
    }
    cout << sum;
    return 0;
}