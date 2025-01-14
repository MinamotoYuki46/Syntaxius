#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(x) (x).begin(), (x).end()

#define mod 1000000007
#define inf 1e18
#define eps 1e-9

#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REPD(i, n) FORD(i, n - 1, 0)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool canFit(int K, const vi & vertical_blocks, const vi & horizontal_blocks){
    vector<int> row1 (K, 0), row2 (K, 0), row3 (K, 0);
    int curRow= 1;

    int curPos = 0;
    for (int width : horizontal_blocks){
        if (curPos + width <= K){
            fill(row2.begin() + curPos, row2.begin() + curPos + width, 1);
            fill(row3.begin() + curPos, row3.begin() + curPos + width, 1);
            curPos += width;
        }
        else return false; 
        
    }

    curPos = 0;
    for (int height : vertical_blocks){
        bool placed = false;
        if (curRow== 1){
            for (int start = 0; start + height <= K; ++start){
                bool fits = true;
                for (int i = 0; i < height; ++i){
                    if (row1[start + i] != 0){
                        fits = false;
                        break;
                    }
                }
                if (fits){
                    fill(row1.begin() + start, row1.begin() + start + height, 1);
                    placed = true;
                    break;
                }
            }
        }
        if (!placed) return false; 
    }
    return true; 
}

int32_t main()
{
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vi block1(n), block2(m);

    REP(i, n) cin >> block1[i];
    REP(j, m) cin >> block2[j];

    sort(all(block1), greater<int>());
    sort(all(block2), greater<int>());

    int low = max( max(block1[0], 2 * block2[0]), 1LL);
    int high = 2000;
    int result = high;

    while (low <= high){
        int mid = (low + high) / 2;
        if (canFit(mid, block1, block2)){
            result = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << result - 1 << endl;

    return 0;
}
