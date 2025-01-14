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
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x)          (x).begin(), (x).end()

#define mod             1000000007
#define inf             1e18
#define eps             1e-9

#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
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

// bool isUnique(const vi & vec, int val){
//     return find(all(vec), val) == vec.end();
// }

// void solve (){
//     int n; cin >> n;
//     vi Vproblems; mii Mproblems;

//     REP(i, n){
//         int x; cin >> x;
//         if (isUnique(Vproblems, x)) Vproblems.pb(x);
//         Mproblems[x]++;
//     }

//     sort(all(Vproblems));

//     int sz = Vproblems.size();

//     if (Mproblems[Vproblems.back()] >= 2){
//         cout << Mproblems[Vproblems.back()] * (Mproblems[Vproblems.back()] - 1) / 2 << '\n'; 
//     }
//     else if (Mproblems[Vproblems.back()] == 1){
//         cout << Mproblems[Vproblems[sz - 2]] << endl;
//     }

// }

// int32_t main(){
//     // c_p_c();
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     w(tc){
//         solve();
//     }


//     return 0;
// }

void solve() {
    int n; cin >> n;
    unordered_set<int> unique_vals;
    unordered_map<int, int> count_vals;

    REP(i, n) {
        int x; cin >> x;
        if (unique_vals.find(x) == unique_vals.end()) {
            unique_vals.insert(x);
        }
        count_vals[x]++;
    }

    vector<int> Vproblems(unique_vals.begin(), unique_vals.end());
    sort(all(Vproblems));

    int sz = Vproblems.size();
    if (sz == 0) {
        cout << 0 << '\n';
        return;
    }

    int max_val = Vproblems.back();
    int max_count = count_vals[max_val];
    if (max_count >= 2) {
        cout << max_count * (max_count - 1) / 2 << '\n';
    } else if (sz > 1) {
        int second_max_val = Vproblems[sz - 2];
        cout << count_vals[second_max_val] << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    w(tc) {
        solve();
    }

    return 0;
}