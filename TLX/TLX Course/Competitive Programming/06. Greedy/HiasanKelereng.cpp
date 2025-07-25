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

bool cmp(pair<char, int> & a, pair<char, int> & b){
    return a.ss > b.ss;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    char ch;
    map<char, int> freq;

    REP(i, n){
        cin >> ch;
        freq[ch]++;
    } 

    if (freq.size() < 3){
        cout << -1; return 0;
    }

    vector<pair<char, int>> v_freq(all(freq));
    sort(all(v_freq), cmp);

    int res, a = v_freq[0].ss, b = v_freq[1].ss, c = v_freq[2].ss;

    if (a == b && b == c) res = 3 * a;
    else if (a == b && b > c) res = 3 * c + 2;
    else if (a > b && b == c) res = 3 * c + 1;
    else if (a > b && b > c) res = 3 * c + 2;

    cout << res;
    
    return 0;
}


// a, a, a = 3a
// a, a, b = 3b + 2
// a, b, b = 3b + 1
// a, b, c = 3c + 2