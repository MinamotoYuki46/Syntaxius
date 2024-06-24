#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x0, y0, x, y, target, num_bombs;
    vi distances;

    cin >> x0 >> y0 >> target;

    while(target--) {
        cin >> x >> y;
        distances.push_back((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y));
    }
    
    sort(distances.begin(), distances.end());

    cin >> num_bombs;
    while(num_bombs--) {
        int bomb_radius;
        cin >> bomb_radius;
        bomb_radius *= bomb_radius;

        cout << upper_bound(distances.begin(), distances.end(), bomb_radius) - distances.begin() << endl;
    }

    return 0;
}
