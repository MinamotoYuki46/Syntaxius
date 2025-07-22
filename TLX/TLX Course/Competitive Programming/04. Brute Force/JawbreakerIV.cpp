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

int r, c;


int traverse(vii & board, int x, int y, int colour){
    if (x < 0 || x >= r || y < 0 || y >= c || board[x][y] != colour) return 0;
    int res = 1;
    board[x][y] = 0;

    res += traverse(board, x + 1, y, colour);
    res += traverse(board, x - 1, y, colour);
    res += traverse(board, x, y + 1, colour);
    res += traverse(board, x, y - 1, colour);

    return res;
}

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


int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    vii board (r, vi (c)), temp (r, vi (c));

    REP(i, r) REP(j, c) cin >> board[i][j];
    temp = board;

    int res = 0;

    REP(i1, r) REP(j1, c){
        int a = traverse(temp, i1, j1, temp[i1][j1]);

        if (a > 1) {
            int pts1 = a * (a - 1);
            restructure(temp);
            res = max(res, pts1);

            REP(i2, r) REP(j2, c){
                if (temp[i2][j2] == 0) continue;

                int b = traverse(temp, i2, j2, temp[i2][j2]);
                if (b > 1){
                    int pts2 = b * (b - 1);
                    res = max(res, pts1 + pts2);
                }
            }
        }       
        temp = board;
    }

    cout << res;

    return 0;
}