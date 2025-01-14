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

int32_t main()
{
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int numA, numB;
    cin >> numA >> numB;
    
    vi potatoA, potatoB;
    double avgA, avgB;
    int addition = 0, sumA = 0, sumB = 0;

    for(int i = 0; i < numA; i++){
        int x;
        cin >> x;
        potatoA.pb(x);
        sumA += x;
    }
    sort(potatoA.begin(), potatoA.end());
    avgA = (double) sumA / numA;
    
    for(int i = 0; i < numB; i++){
        int x;
        cin >> x;
        potatoB.pb(x);
        sumB += x;
    }
    sort(potatoB.begin(), potatoB.end());
    avgB = (double) sumB / numB;

    while(avgA <= avgB && !potatoB.empty()){
        int valueToAdd = potatoB.back();
        
        int count = 0;
        while(!potatoB.empty() && potatoB.back() == valueToAdd) {
            potatoA.pb(potatoB.back());
            potatoB.pop_back();
            count++;
        }

        addition += valueToAdd * count;
        sumA += valueToAdd * count;
        sumB -= valueToAdd * count;
        numA += count;
        numB -= count;

        avgA = (double)sumA / numA;
        avgB = numB > 0 ? (double)sumB / numB : 0;
    }

    cout << addition << endl;
    return 0;
}
