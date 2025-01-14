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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


vector<vi> adj;
vector<pii> cost;
vector<bool> visited;

int sum = 0, currentCost;

void dfs(int node) {
    visited[node] = true;
    sum += currentCost;

    for (auto x : adj[node]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

int32_t main() {
    c_p_c();
    int v, e;
    cin >> v >> e;
    
    cost.resize(v);
    visited.resize(v, false);
    adj.resize(v);

    for (int i = 0; i < v; i++) {
        cost[i].ff = i;             
        cin >> cost[i].ss;
    }

    sort(cost.begin(), cost.end(), [](const pii& a, const pii& b) {
        return a.ss < b.ss;
    });



    for (int i = 0; i < e; i++) {
        int src, dest;
        cin >> src >> dest;
        src--, dest--; 
        adj[src].pb(dest);
    }

    for (int i = 0; i < v; i++) {
        if (!visited[cost[i].ff]) {
            currentCost = cost[i].ss;
            dfs(cost[i].ff);
        }
    }
    cout << sum << endl;
    return 0;
}
