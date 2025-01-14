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

void solve(string str){
    int max_even = LLONG_MIN;
    int index_even = -1;

    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])){
            int num = str[i] - '0'; 
            if (num % 2 == 0){
                if (num >= max_even){
                    max_even = num;
                    index_even = i;
                }
            }
        }
    }
    //cout << max_even << endl;

    if (index_even == -1){
        cout << 0 << endl; 
        return;
    }

    int result = 0;

    for (int i = 0; i < index_even; i++){
        if(isdigit(str[i])) {
            result = (result * 10 + (str[i] - '0')) % mod;
        }
    }

    result = result * 10 + max_even;

    cout << result % mod << endl;
}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;

    solve(str);

    return 0;
}
