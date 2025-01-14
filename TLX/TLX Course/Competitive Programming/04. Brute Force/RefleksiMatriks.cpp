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

void analyze(vector<vi>& a, vector<vi>& b) {
    int n = a.size();
    
    bool identical = true;
    bool isHorizontal = true, isVertical = true, isDiagonal1 = true, isDiagonal2 = true;

    // Identical Check
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j]) {
                identical = false;
                break;
            }
        }
        if (!identical) break;
    }

    // Horizontal 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[n - i - 1][j]) {
                isHorizontal = false;
                break;
            }
        }
        if (!isHorizontal) break;
    }

    // Vertical 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][n - j - 1]) {
                isVertical = false;
                break;
            }
        }
        if (!isVertical) break;
    }

    // Diagonal (\) 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (a[i][j] != b[j][i]) {
                isDiagonal1 = false;
                break;
            }
        }
        if (!isDiagonal1) break;
    }

    // Diagonal (/) 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[n - j - 1][n - i - 1]) {
                isDiagonal2 = false;
                break;
            }
        }
        if (!isDiagonal2) break;
    }

    if (identical) cout << "identik" << endl;
    else if (isHorizontal) cout << "horisontal" << endl;
    else if (isVertical) cout << "vertikal" << endl;
    else if (isDiagonal1) cout << "diagonal kanan bawah" << endl;
    else if (isDiagonal2) cout << "diagonal kiri bawah" << endl;
    else cout << "tidak identik" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    c_p_c();
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    vector<vi> arr1(r1, vi(c1));

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> arr1[i][j];
        }
    }

    cin >> r2 >> c2;
    vector<vi> arr2(r2, vi(c2));

    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> arr2[i][j];
        }
    }

    if (r1 == r2 && c1 == c2 && r1 == c1) {
        analyze(arr1, arr2);
    } else {
        cout << "tidak identik" << endl;
    }

    return 0;
}
