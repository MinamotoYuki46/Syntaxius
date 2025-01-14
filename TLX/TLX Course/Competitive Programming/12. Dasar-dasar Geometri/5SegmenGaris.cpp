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
#define vii             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int> >
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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REPD(i, n) FORD(i, n - 1, 0)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct Point {
    int x, y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) {
        return true;
    }
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclockwise
}

bool isIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Debugging output
    cout << "o1: " << o1 << ", o2: " << o2 << ", o3: " << o3 << ", o4: " << o4 << endl;

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special cases
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int32_t main() {
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(tc) {
        Point p1, q1, p2, q2;
        cin >> p1.x >> p1.y >> q1.x >> q1.y;
        cin >> p2.x >> p2.y >> q2.x >> q2.y;
        cout << "Processing: (" << p1.x << ", " << p1.y << "), (" << q1.x << ", " << q1.y << "), (" << p2.x << ", " << p2.y << "), (" << q2.x << ", " << q2.y << ")" << endl;
        cout << (isIntersect(p1, q1, p2, q2) ? "YA" : "TIDAK") << endl;
    }

    return 0;
}
