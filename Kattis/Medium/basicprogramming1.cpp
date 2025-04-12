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

void case2(int a, int b){
    if(a > b){
        cout << "Bigger";
    }else if(a == b){
        cout << "Equal";
    }else{
        cout << "Smaller";
    }
}

void case3(vi N){
    std::sort(N.begin(), N.begin() + 3);
    cout << N[1];
}

void case4(vi N){
    int sum = 0;
    REP(i, N.size()){
        sum += N[i];
    }

    cout << sum;
}

void case5(vi N){
    int sum = 0;
    REP(i, N.size()){
        if(N[i] % 2 == 0) sum += N[i];
    }

    cout << sum;
}

void case6(vi N){
    REP(i, N.size()){
        cout << (char) ((N[i]%26) + 97);
    }
}

void case7(vi N){
    int i = 0;

    vector<bool> visited(N.size(), false);
    while(true){
        if(i > N.size()-1){
            cout << "Out";
            break;
        }else if(i == N.size() - 1){
            cout << "Done";
            break;
        }else if(visited[i]){
            cout << "Cyclic";
            break;
        }
        visited[i] = true;
        i = N[i];
    }
}

int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n >> t;

    vi N_num(n, 0);
    REP(i, n){
        cin >> N_num[i];
    }

    switch (t)
    {
    case 1:
        cout << 7;
        break;
    
    case 2:
        case2(N_num[0], N_num[1]);
        break;
    
    case 3:
        case3(N_num);
        break;
    
    case 4:
        case4(N_num);
        break;
    
    case 5:
        case5(N_num);
        break;
    
    case 6:
        case6(N_num);
        break;
    
    case 7:
        case7(N_num);
        break;
    

    default:
        break;
    }

    return 0;
}