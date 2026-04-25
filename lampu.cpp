// ada sebuah lampu, dan diberi N, kondisi awal mati
// lampu itu berubah status kalau tomobl ke i membagi habis N
// ditanya, kondisi akhir

#include <bits/stdc++.h>
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
#define vb              vector<bool>
#define vbb             vector<vb>
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define trailz(x)       __builtin_ctzll(x)
#define leadz(x)        __builtin_clzll(x)
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


// input 5: lampu mati
// 4: lampu nyala

// n < 1e18


// kasus n 5
// tombol 1: lampu nyala
// tombol 2: -
// tombol 3: -
// tombol 4: - 
// tombol 5: lampu mati

//solusi 1: compare semua nilai i sampai n, dengan n
// O(n)

// solusi 2:

// faktorisasi bilangan
// 5: 1, 5
// 4: 1, 2, 4
// 12: 1, 2, 3, 4, 6, 12


// faktorisasi prima
// 2^2 * 3^1 => 3 * 2

// O(sqrt(n))

// solusi 3
// jumlah faktorisasi bilangan genap, mati. kalau ganjil, nyala
// umumnya faktorisasi builangan genap. karena pasangan a x b

// a x a? bilangan kuadrat
// 16: 1, 2, 4, 8, 16
// O(1)


// int32_t main(){
//     //c_p_c();
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int n; cin >> n;

//     int div_count = 0;

//     for(int i = 1; i <= n; i++){
//         if (n % i == 0) div_count++;
//     }

//     if (div_count % 2 == 0){
//         cout << "lampu mati";
//     }
//     else {
//         cout << "lampu menyala";
//     }

//     return 0;
// }

// int32_t main(){
//     int n; cin >> n;

//     // prime generator
//     int num = n;
//     int div_count = 1;

//     for(int i = 2; i * i <= num; i++){
//         int factor_count = 0;
//         while(num % i == 0){
//             factor_count++;
//             num /= i;
//         }

//         div_count *= (factor_count + 1);
//     }

//     if (num > 1) div_count *= 2;

//     if (div_count % 2 == 0){
//         cout << "lampu mati";
//     }
//     else {
//         cout << "lampu menyala";
//     }

//     return 0;
// }

int32_t main(){
    int n; cin >> n;

    int num = round(sqrt(n));

    // int n 8; sqrt(8) = 2.8284271247; 3; 
    // sqrt (1, 4, 9, 16) => 1.0, 2.0, 3, 4

    if (num * num != n) {
        cout << "lampu mati";
    }
    else {
        cout << "lampu nyala";
    }


    return 0;
}


