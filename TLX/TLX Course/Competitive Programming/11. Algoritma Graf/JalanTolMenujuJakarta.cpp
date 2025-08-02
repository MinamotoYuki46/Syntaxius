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
#define vb              vector<bool>
#define vii             vector<vi>
#define vbb             vector<vb>
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

int n, m, t, src, dst;
vector<vector<pii>> graph;


int dijkstra(){
    vii dist (n + 1, vi (2, INF));

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, src});
    dist[src][0] = 0;

    while(!pq.empty()){
        auto [d, used_tol, u] = pq.top(); pq.pop();

        if (dist[u][used_tol] < d) continue;

        for(auto [v, tol]: graph[u]){
            if (tol == 0){
                if (dist[v][used_tol] > d + 1) {
                    dist[v][used_tol] = d + 1;
                    pq.push({dist[v][used_tol], used_tol, v});
                }
            }
            else if (tol == 1 && used_tol == 0) {
                if (dist[v][1] > d + 1) {
                    dist[v][1] = d + 1;
                    pq.push({dist[v][1], 1, v});
                }
            }
        }
    }

    return min(dist[dst][0], dist[dst][1]);
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t >> src >> dst;
    graph.resize(n + 1);
    
    int u, v;
    FOR(i, 1, m + 1){
        cin >> u >> v;
        graph[u].pb({v, 0});
        graph[v].pb({u, 0});
    }

    FOR(i, 1, t + 1){
        cin >> u >> v;
        graph[u].pb({v, 1});
        graph[v].pb({u, 1});
    }

    cout << dijkstra();

    return 0;
}