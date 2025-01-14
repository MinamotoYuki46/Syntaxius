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

    int n; cin >> n;
    
    pqb left; pqs right;

    FOR(i, 1, n+1){
        int x; cin >> x;

        if (!left.empty() && x < left.top()) left.push(x);
        else right.push(x);

        while(left.size() > right.size()){
            right.push(left.top());
            left.pop();
        }

        while(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }

        if (i % 2) cout << left.top() << '\n';
        else {
            int m = (left.top() + right.top()) / 2;
            cout << m;
            if ((left.top() + right.top()) % 2) cout << ".5" << '\n';
            else cout << '\n';
        }
    }
    return 0;
}