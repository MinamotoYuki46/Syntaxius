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
#define pqs             priority_queue<int, vi, greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x)          (x).begin(), (x).end()

#define MOD             1000000007
#define INF             1e18
#define EPS             1e-9
#define DEG_TO_RAD      0.0174532925199432957692
#define RAD_TO_DEG      57.2957795130823208768
#define PI              3.14159265358979323846
#define E               2.71828182845904523536

#define ps(x,y)         fixed << setprecision(y) << x
#define mk(arr,n,type)  type *arr = new type[n];
#define w(x)            int x; cin >> x; while (x--)
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

int inversionCount = 0;

void merge(vi & data, int left, int mid, int right){
    int lSize = mid - left + 1;
    int rSize = right - mid;

    vi lSide(lSize), rSide(rSize);

    REP(i, lSize) lSide[i] = data[left + i];
    REP(j, rSize) rSide[j] = data[mid + j + 1];

    int l = 0, r = 0, k = left;

    while(l < lSize && r < rSize){
        if (lSide[l] <= rSide[r]){
            data[k] = lSide[l];
            l++;
        }
        else {
            data[k] = rSide[r];
            r++;
            inversionCount += (lSize - l);
        }
        k++;
    }

    while(l < lSize){
        data[k] = lSide[l];
        l++, k++;
    }

    while(r < rSize){
        data[k] = rSide[r];
        r++, k++;
    }
}

void mergeSort(vi & data, int begin, int end){
    if (begin >= end) return;

    int mid = begin + (end - begin) / 2;
    mergeSort(data, begin, mid);
    mergeSort(data, mid + 1, end);
    merge(data, begin, mid, end);

}

int32_t main(){
    //c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; vi data(n);

    REP(i, n) cin >> data[i];

    mergeSort(data, 0, data.size() - 1);
    cout << inversionCount;

    return 0;
}