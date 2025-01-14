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

#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
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

int modPow(int x, int y, int p){
    int res = 1;
    x %= p;

    while (y > 0) {
        if (y & 1)  
            res = (res * x) % p;
        y = y >> 1;  
        x = (x * x) % p;  
    }
    return res;
}

void precomputeFactorials(int n, vi & fact, vi & invFact) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[n] = modPow(fact[n], MOD - 2, MOD);  
    for (int i = n - 1; i > 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

int comb(int n, int r, const vi & fact, const vi & invFact){
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % MOD) * invFact[n - r] % MOD;
}

int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vi fact (1000 + 1), invFact (1000 + 1);
    precomputeFactorials(1000, fact, invFact);

    int res = 0;
    for(int i = a; i <= b; i++){
        res = (res + comb(n, i, fact, invFact)) % MOD;
    }
    cout << res;
    

    return 0;
}