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
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int factorial(int n) { 
    if(n == 0) 
        return 1; 
    int fact = 1; 
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % mod;
    }
    return fact; 
} 

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int32_t main(){
    //c_p_c();
    
    int val;
    cin >> val;

    map<int, int> key;

    for (int i = 2; i * i <= val; i++) {
        while (val % i == 0) {
            val /= i;
            key[i]++;
        }
    }
    if (val > 1) {
        key[val]++;
    }

    int counter = 0;
    for (auto &x : key) {
        counter += x.ss;
    }

    int result = factorial(counter);
    for (auto &x : key) {
        result = (result * modInverse(factorial(x.ss), mod)) % mod;
    }

    cout << result << endl;

    return 0;
}
