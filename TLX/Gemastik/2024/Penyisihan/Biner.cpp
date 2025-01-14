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
#define ull             unsigned long long

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

ull toggleIthBit(int num, int i) {
    int mask = 1ULL << i;
    return num ^ mask;
}

int comb(int n, int k){
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    if (k > n - k) k = n - k; 

    int result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    
    return result;
}

void findKthSequence(int n, int k, int index, int start, vi & result) {
    if (k == 0) return;

    for (int i = start; i <= 29 + (n - k); ++i) {
        int numCombinations = comb(29 + (n - k) - i, k - 1);
        
        if (index <= numCombinations) {
            result.push_back(i);
            findKthSequence(n, k - 1, index, i + 1, result);
            return;
        }
        
        index -= numCombinations;
    }
}

vi getKthSequence(int n, int k, int index) {
    vi result;
    findKthSequence(n, k, index, 0 + (n - k), result);
    return result;
}

ull solve(int n){
    if (n == 1) return (1ULL << 30) - 1;

    int base = 30;
    int lo = 2, hi = 31, phase = 1;

    //Finding phase
    while(n > hi){
        lo = hi + 1;
        hi += comb(base, phase + 1);
        phase++;
    }

    // return phase;

    base += phase; 
    ull num = (1ULL << (base)) - 1; 

    cout << phase << endl;
    
    vi ind (phase, 0), base30 (phase, 29 + phase - 1);


    n -= (lo - 1);
    cout << "n : "<< n << endl;

    ind = getKthSequence(phase, phase, n);
    // reverse(all(ind));

    REP(k, phase){
        cout << base30[k] - ind[k] << ' ';
    }

    cout << endl;

    REP(a, phase){
        num = toggleIthBit(num, base30[a] - ind[a]);
    }
    // cout << endl;
    return num;
    
    

    

} 

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // unsigned long long num = (1ULL << 31) - 1;
    // // cout << num << endl;
    // // cout << num << endl;
    // num = toggleIthBit(num, 0);
    // // num = toggleIthBit(num, 30);
    // // num = toggleIthBit(num, 29);

    // cout << num << '\n';
    
    // int N; 
    // while(true){
    //     cin >> N;
    //     if (!N) break;
    //     cout << N << " : " << solve(N) << '\n' << '\n';
    // }

    FOR(i, 4527, 31931){
        cout << i << " : " << solve(i) << '\n';
    }
    return 0;
}