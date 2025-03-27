/*
Input
Input consists of two space-separated integers, X and Y. 
X is the point on B where A is zero. 
Y is the number of degrees in B that equal a change of a single degree in A.

Output
Output the temperature where both scales are the same. 
This number must have an absolute or relative error of at most 10_-6. 
If no such temperature exists, output “IMPOSSIBLE” (without the quotes) instead. 
If more than one such point exists, output “ALL GOOD” (without the quotes) instead.

Limits
-100 <= X <= 100
1 <= Y <= 100

*/

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

    double X, Y;
    cin >> X >> Y;

    double intersection = -X/(Y-1);

    if(X==0 & Y==1){
        cout << "ALL GOOD";
    }else if(Y==1){
        cout << "IMPOSSIBLE";
    }else{
        cout << fixed << setprecision(9) << intersection;
    }
    
    return 0;
}