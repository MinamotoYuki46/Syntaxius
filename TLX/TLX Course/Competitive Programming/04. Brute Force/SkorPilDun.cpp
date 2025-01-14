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

vi pts (5), temp (5, 0);
bool valid;
int team;

void match(int teamA, int teamB){
    if (teamB == team){
        match(teamA + 1, teamA + 2);
        return;
    }
    if (teamA == team){
        bool current = true;
        for(int i = 0; i < team; i++){
            if(pts[i] != temp[i]){
                current = false;
                break;
            }
        }
        if (current) valid = true;
        return;
    }

    temp[teamA] += 3; temp[teamB] += 0;
    match(teamA, teamB + 1);
    temp[teamA] -= 3; temp[teamB] -= 0;

    temp[teamA] += 1; temp[teamB] += 1;
    match(teamA, teamB + 1);
    temp[teamA] -= 1; temp[teamB] -= 1;

    temp[teamA] += 0; temp[teamB] += 3;
    match(teamA, teamB + 1);
    temp[teamA] -= 0; temp[teamB] -= 3;
}

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(tc){
        cin >> team;
        for(int i = 0; i < team; i++) cin >> pts[i];
        valid = false;
        match(0, 1);
        cout << (valid? "YES" : "NO") << endl;
    }

    return 0;
}