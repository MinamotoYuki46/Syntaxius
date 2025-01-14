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

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int path[48];
bool vis[9][9];

int explore(int pathIdx, int curR, int curC){
    if ((vis[curR][curC - 1] && vis[curR][curC + 1]) && 
        (!vis[curR - 1][curC] && !vis[curR + 1][curC])) return 0;
    if ((vis[curR - 1][curC] && vis[curR + 1][curC]) &&
        (!vis[curR][curC - 1] && !vis[curR][curC + 1])) return 0;

    if (curR == 7 && curC == 1){
        if (pathIdx == 48) return 1;
        return 0;
    }

    if (pathIdx == 48) return 0;

    int res = 0;
    vis[curR][curC] = true;

    if(path[pathIdx] < 4){
        int nxtR = curR + dr[path[pathIdx]];
        int nxtC = curC + dc[path[pathIdx]];
        if (!vis[nxtR][nxtC]) res += explore(pathIdx + 1, nxtR, nxtC);
    }
    else{
        REP(i, 4){
            int nxtR = curR + dr[i];
            int nxtC = curC + dc[i];
            if (vis[nxtR][nxtC]) continue;
            res += explore(pathIdx + 1, nxtR, nxtC);
        }
    }

    vis[curR][curC] = false;
    return res;
}


int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;

    REP(i, 48){
        char cur = str[i];

        if (cur == 'U')         path[i] = 0;
        else if (cur == 'R')    path[i] = 1;
        else if (cur == 'D')    path[i] = 2;
        else if (cur == 'L')    path[i] = 3;
        else                    path[i] = 4;
    }

    REP(i, 9){
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }

    FOR(i, 1, 8){
        FOR(j, 1, 8) vis[i][j] = false;
    }

    int startIdx = 0;
    int startR = 1;
    int startC = 1;

    cout << explore(startIdx, startR, startC);
    return 0;
}