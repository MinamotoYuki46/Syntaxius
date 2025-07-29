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

int walk[8][2] = {
    {-2, -1}, {-2, 1},
    {-1, -2}, {-1, 2},
    {1, -2}, {1, 2},
    {2, -1}, {2, 1}
};

int n, m, k, s, i, j;
vii grid;
vector<pii> horse;

bool bfs(int target_x, int target_y){
    queue<pii> q;

    REP(h, k){
        q.push({horse[h].ff, horse[h].ss});
    }

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        if (target_x == x && target_y == y) break;
        if (grid[x][y] == s) continue;

        REP(z, 8){
            int dx = x + walk[z][0];
            int dy = y + walk[z][1];

            if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] > grid[x][y] + 1){
                q.push({dx, dy});
                grid[dx][dy] = grid[x][y] + 1;
            }
        }
    }

    // REP(a, n){
    //     REP(b, m){
    //         cout << (grid[a][b] == INT_MAX? 0:grid[a][b]) << ' ';
    //     }
    //     cout << '\n';
    // }

    return grid[target_x][target_y] != INT_MAX;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    w(tc){
        cin >> n >> m >> k >> s >> i >> j; i--, j--;

        grid.assign(n, vi (m, INT_MAX));
        horse.assign(k, pii ());

        REP(a, k){
            int x, y; cin >> x >> y; x--, y--;
            horse[a] = {x, y};
            grid[x][y] = 0;
        } 

        cout << (bfs(i, j)? "TRUE":"FALSE") << '\n';
    }

    return 0;
}