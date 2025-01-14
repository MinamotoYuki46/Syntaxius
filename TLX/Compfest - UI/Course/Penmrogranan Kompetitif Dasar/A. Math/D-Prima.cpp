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


vector<bool> isPrime(1e5, true);
vi prime;


void sieveOfEratosthenes() {
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= 1e5; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= 1e5; i += p)
                isPrime[i] = false;
        }
    }
    REP(i, 1e5){
        if(isPrime[i]){
            prime.pb(i);
        }
    }
}


void primeGenerator(){
    int flag = 0;
    for (int i = 1 ; i < 1000000; i++){
        flag = 0;
        for(int j = 2; j <= sqrt(i) ; j++){
            if (i % j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0 && i != 1){
            prime.push_back(i);
        }
    }
}


int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // sieveOfEratosthenes();
    primeGenerator();
    int n, k; cin >> n >> k;

    REP(i, n){
        cout << prime[k * i] << '\n';
    }
    return 0;
}