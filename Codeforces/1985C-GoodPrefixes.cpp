#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
using namespace std;


ll prefix(vector<ll>& arr, ll n, ll maks, ll idx){
    ll sum;
    if(idx == 0){
        arr.push_back(n);
        sum = arr[0];
    }
    else {
        arr.push_back(n + arr[arr.size()-1]);
        sum  = arr[arr.size()-1];
    }

    if(sum - maks == maks) return 1;
    else return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n ;++i){
        cin >> arr[i];
    }

    ll cnt = 0;
    vector<ll> temp;
    ll maxs = INT_MIN;
    for(int i = 0; i < n; ++i){
        maxs = max(arr[i], maxs);
        cnt += prefix(temp, arr[i], maxs, i);
    }

    cout << cnt<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test; cin >> test;
    for(int  i = 1; i <= test; ++i){
        solve();
    }
    return 0;
    
}
