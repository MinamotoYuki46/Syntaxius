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

int r, c, ans = 0;
vector<pii> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void restructure(vii & board){
    REP(j, c){
        int target = r - 1;
        REPD(i, r){
            if (board[i][j] != 0) {
                swap(board[i][j], board[target][j]);
                target--;
            }
        }
    }
}

void solve(vii & board, int res){
    ans = max(ans, res);
    vbb visited (r, vb (c, false));

    REP(i, r) REP(j, c){
        if (board[i][j] == 0 || visited[i][j]) continue;

        int colour = board[i][j];
        vector<pii> group;
        queue<pii> q;
        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            group.pb({x, y});

            for(auto [dx, dy]: dir){
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (board[nx][ny] == colour && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        if (group.size() >= 2){
            vii new_board = board;
            for(auto [x, y]: group) new_board[x][y] = 0;
            restructure(new_board);
            int cur_res = group.size() * (group.size() - 1);
            solve(new_board, res + cur_res);
        }
    }
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    vii board (r, vi (c));

    REP(i, r) REP(j, c) cin >> board[i][j];

    solve(board, 0);

    cout << ans;

    return 0;
}