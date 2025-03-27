/*
There are 3 kinds of victory cards in Dominion:

Province (costs 8, worth 6 victory points)
Duchy (costs 5, worth 3 victory points)
Estate (costs 2, worth 1 victory point)

And, there are 3 kinds of treasure cards:

Gold (costs 6, worth 3 buying power)
Silver (costs 3, worth 2 buying power)
Copper (costs 0, worth 1 buying power)

Input
The input consists of a single test case on a single line, which contains three non-negative integers G, S, C 
( G + S + C <= 5) indicating the number of Golds, Silvers, and Coppers Jake draws in his hand.

Output
Output the best victory card (Province, Duchy, or Estate) and the best treasure card (Gold, Silver, or Copper) Jake can buy this turn, 
separated with " or ", in this order. If Jake cannot afford any victory cards, output only the best treasure card he can buy.
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

    int G, S, C;
    cin >> G >> S >> C;
    int buy_pow = G*3 + S*2 + C*1;
    
    if(buy_pow >= 2 ){
        if(buy_pow >= 8){
            cout << "Province or ";
        }else if(buy_pow >= 5){
            cout << "Duchy or ";
        }else{
            cout << "Estate or ";
        }
    }

    if(buy_pow >= 6){
        cout << "Gold";
    }else if(buy_pow >= 3){
        cout << "Silver";
    }else{
        cout << "Copper";
    }

    return 0;
}