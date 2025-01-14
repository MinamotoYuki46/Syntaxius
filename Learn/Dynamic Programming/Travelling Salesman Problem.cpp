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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


//Brute Force Approach O(n!)
int TSP(vii & graph, int src){
    vi vertex;

    for(int i = 0; i < graph.size(); i++){
        if (i != src) vertex.pb(i);
    }

    int min_path = INT_MAX;

    while(next_permutation(vertex.begin(), vertex.end())){
        int current_cost = 0;
        int key = src;

        for(int i = 0; i < vertex.size(); i++){
            current_cost += graph[key][vertex[i]];
            key = vertex[i];
        }
        current_cost += graph[key][src];

        min_path = min(min_path, current_cost);
    }

    return min_path;
};


// DP Approach O(n ^ 2 * ⋅2 ^ n)

int TSP_DP(vii & graph){
    int n = graph.size();
    vii dp (1 << n, vi (n, INT_MAX));

    dp[1][0] = 0;

    for(int mask = 1; mask < (1 << n); mask++){
        for (int u = 0; u < n; u++){
            if (mask & (1 << u)){
                for (int v = 0; v < n; v++){
                    if (mask & (1 << v) && u != v){
                        dp[mask][u] = min(dp[mask][u], dp[mask ^ (1 << u)][v] + graph[v][u]);
                    }
                }
            }
        }
    }

    for(int i = 0; i < (1 << n); i++){
        for (int j = 0; j < (1 << n); j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    int ans = INT_MAX;
    for (int u = 1; u < n; u++){
        ans = min(ans, dp[ (1 << n) - 1][u] + graph[u][0]);
    }

    return ans;
};


int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, src = 0;
    cin >> n;

    vii graph (n, vi (n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    // cout << "BF Approach" << endl;
    // cout << TSP(graph, src) << endl;


    cout << "DP Approach" << endl;
    cout << TSP_DP(graph) << endl;


    return 0;
}