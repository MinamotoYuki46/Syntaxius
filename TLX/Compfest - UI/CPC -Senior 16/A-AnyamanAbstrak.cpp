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

int32_t main()
{
    // c_p_c();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi atas(n), bawah(n);
    unordered_map<int, pii> posBawah;

    REP(i, n){
        cin >> atas[i];
    }

    REP(i, n){
        cin >> bawah[i];
        if (posBawah.find(bawah[i]) == posBawah.end()){
            posBawah[bawah[i]] = {i, i};
        }
        else{
            posBawah[bawah[i]].first = min(posBawah[bawah[i]].first, i);
            posBawah[bawah[i]].second = max(posBawah[bawah[i]].second, i);
        }
    }


    int count = 0;

    int mid = n / 2;
    REP(i, n){
        int pivot = atas[i];
        int left = i, right;        

        // if (left < mid){
        //     right = posBawah[atas[i]].front();
        // }
        // else{
        //     right = posBawah[atas[i]].back();
        // }
        // count += abs(left - right);

        if (posBawah.find(pivot) != posBawah.end()){
            auto [min_pos, max_pos] = posBawah[pivot];
            int max_distance = max(abs(left - min_pos), abs(left - max_pos));
            count += max_distance;
        }
    }
    cout << count;

    return 0;
}
