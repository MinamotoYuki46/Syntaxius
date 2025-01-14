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

int gcd(int a, int b){
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int min_animals(int n, const vi & v, const vi & e){
    vii graph(n);

    REP(i, n){
        FOR(j, i + 1, n){
            if (v[i] != v[j] && gcd(e[i], e[j]) != 1){
                graph[i].pb(j);
                graph[j].pb(i);
            }
        }
    }

    vi colour(n, -1);

    auto BFS = [&](int start) -> int {
        queue<int> q;
        q.push(start);
        colour[start] = 0;

        vi count (2, 0);
        count[0]++;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbour : graph[node]){
                if (colour[neighbour] == -1){
                    colour[neighbour] = 1 - colour[node];
                    count[colour[neighbour]]++;
                    q.push(neighbour);
                }
                else if (colour[neighbour] == colour[node]){
                    return -1;
                }
            }
        }
        return min(count[0], count[1]);
    };

    int total_to_move = 0;

    REP(i, n) {
        if (colour[i] == -1) {
            int result = BFS(i);
            if (result == -1) {
                return -1;  
            }
            total_to_move += result;
        }
    }

    return total_to_move;
}

int32_t main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vi v(n), e(n);

    REP(i, n) cin >> v[i];
    REP(i, n) cin >> e[i];

    cout << min_animals(n, v, e);

    return 0;
}

