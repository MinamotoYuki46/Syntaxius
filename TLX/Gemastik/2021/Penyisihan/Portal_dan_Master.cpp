#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<ll> edges[100005]; 
bool vis[100005];
vector<ll> arr;

ll dfs(ll v){
    vis[v] = 1;
    int stamina = arr[v];

    for(ll x: edges[v]){
        if(!vis[x]){
            stamina += dfs(x);
        }
    }

    return stamina;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll cave, tunnel;
    cin >> cave >> tunnel;
    for(ll i = 0; i < cave; ++i){
        ll x; cin >> x;
        arr.push_back(x);
    }

    for(ll i = 0; i < tunnel; ++i){
        ll u, v;
        cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    ll ans = 0;
    vector<ll> temp; 
    for(ll i = 0; i < cave; ++i){
        if(!vis[i]){
            temp.push_back(dfs(i));
        }
    }

    sort(temp.begin(), temp.end());
    for(ll i = 0; i < temp.size(); ++i){
        ans += temp[i] * (temp.size() - i);
    }
    cout << ans;
    return 0;
}