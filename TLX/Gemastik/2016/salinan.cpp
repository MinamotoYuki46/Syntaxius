#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_backA
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
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    
    c_p_c();
    int tc; cin >> tc;

    while(tc--){
        int box; cin >> box;
        int arr[box][3];
        int maks = 0;
        int minim = 0;
        for(int i = 0; i < box; ++i){
            int temp1 = INT_MAX;
            int temp2 = INT_MIN;
            for(int j = 0; j < 3; ++j){
                cin >> arr[i][j];
                temp1 = min(temp1, arr[i][j]);
                temp2 = max(temp2, arr[i][j]);
            }
            minim += temp1;
            maks += temp2;
        }
        cout << minim <<" " << maks<<endl;
    }
    return 0;
}