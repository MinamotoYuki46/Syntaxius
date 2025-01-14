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

void knapsack(int num_items, int capacity, vector<pii> & items){
    vii dp (num_items + 1, vi (capacity + 1, 0));
    vector<vector<bool>> selected(num_items + 1, vector<bool>(capacity + 1, false));

    FOR(i, 1, num_items + 1){
        REP(c, capacity + 1){
            if (c >= items[i - 1].ff){
                if (dp[i - 1][c] < dp[i - 1][c - items[i - 1].ff] + items[i - 1].ss){
                    dp[i][c] = dp[i - 1][c - items[i - 1].ff] + items[i - 1].ss;
                    selected[i][c] = true;
                } else {
                    dp[i][c] = dp[i - 1][c];
                }
            } else {
                dp[i][c] = dp[i - 1][c];
            }
        }
    }

    // cout << "Maximum Value: " << dp[num_items][capacity] << endl;

    vi res;
    int c = capacity;
    FORD(i, num_items, 1){
        if (selected[i][c]){
            res.pb(i - 1); 
            c -= items[i - 1].ff;
        }
    }

    sort(all(res));

    // cout << "Selected Items: ";
    for (int index : res){
        cout << index + 1 << endl;
    }
    // cout << endl;
}

int32_t main(){
    c_p_c(); 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, capacity;
    cin >> capacity >> n;
    vector<pii> items(n);

    // ff for weight and ss for value
    REP(i, n){
        cin >> items[i].ff >> items[i].ss;
    }

    knapsack(n, capacity, items);
    return 0;
}
