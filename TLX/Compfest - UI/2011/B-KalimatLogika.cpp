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
    int state = 1, temp = 1, val0, val1;
    for(int i = 0; i < str.size(); i++){
        if (str[i] == 'B' || str[i] == 'S') {
            temp = (str[i] == 'B') ? 1 : 0;
            for(int j = i - 1; str[j] == '~'; j--) {
                temp = !temp;
            }
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            temp = -1;
            val0 = 1;
            for(int j = i - 1; str[j] == '~'; j--) {
                val0 = !val0;
            }
            for(int j = i + 1; j < str.size(); j++) {
                if(str[i] == str[j]) {
                    val1 = 1;
                    for(int k = j - 1; str[k] == '~'; k--) {
                        val1 = !val1;
                    }
                    if (val0 != val1) temp = 0;
                }
            }
        }

        if (temp == 0) {
            state = 0;
            break;
        } else if (temp == -1) {
            state = -1;
        }
    }
    if (state == -1) cout << "mungkin";
    else if (state == 0) cout << "salah";
    else if (state == 1 ) cout << "benar";

    cout << endl;
};


int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    w(tc){
        cin >> str;
        solve(str);
    }
    return 0;
}