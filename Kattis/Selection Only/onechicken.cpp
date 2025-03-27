/*
Input
The first line contain integers N and M the number of people at the buffet 
and the number of pieces of chicken Dr. Chaz is providing.

Output
Output a single line of the form “Dr. Chaz will have piece[s] of chicken left over!”, 
if Dr. Chaz has enough chicken and pieces of chicken will be left over, 
or “Dr. Chaz needs more piece[s] of chicken!” 
if Dr. Chaz does not have enough pieces of chicken and needs more.
*/

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

int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;

    cin >> N >> M;
    if(N > M){
        cout << "Dr. Chaz needs " << N-M;
        if(N-M == 1){
            cout << " more piece of chicken!";
        }else{
            cout << " more pieces of chicken!";
        }

    }else{
        cout << "Dr. Chaz will have " << M-N;
        if(M-N == 1){
            cout << " piece of chicken left over!";
        }else{
            cout << " pieces of chicken left over!";
        }
    }

    return 0;
}