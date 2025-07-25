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

bool cmp(vi & a, vi & b){
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(int x, vi & weight, vi & capacity){
    int n = weight.size();

    vii items (n, vi (2));

    REP(i, n) {
        items[i][0] = capacity[i];
        items[i][1] = weight[i];
    }

    sort(all(items), cmp);
    
    double res = 0.0;
    int cur_capacity = x;

    REP(i, n){
        if (items[i][1] <= cur_capacity){
            res += items[i][0];
            cur_capacity -= items[i][1];
        }
        else {
            res += (1.0 * items[i][0] / items[i][1]) * cur_capacity;
            break;
        }
    }

    return res;
}



int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;
    vi weight(n), price(n);

    REP(i, n) cin >> weight[i];
    REP(i, n) cin >> price[i];

    cout << ps(fractionalKnapsack(x, weight, price), 5);

    return 0;
}