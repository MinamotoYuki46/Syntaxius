// QALY is a product of quality of life and number of years of the period

// Input
// The first line of input contains a single integer N, which is the number of periods of constant quality of life during the person’s lifetime.

// The next lines describe the periods of life. 
// Each of these lines contains two real numbers 0.0 <= q <= 1.0 which is the quality of life in this period, 
// and 0.0 <= y <= 100.0 , which is the number of years in this period. All real numbers will be specified to exactly one decimal place.

// Output
// Display the QALY accumulated by the person. 
// Your answer will be considered correct if its absolute error does not exceed 10^-3


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
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
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

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    double sum = 0;
    REP(i, N){
        double q, y;
        cin >> q >> y; 
        sum += q * y;
    }

    cout << fixed << setprecision(3) << sum;

    return 0;
}