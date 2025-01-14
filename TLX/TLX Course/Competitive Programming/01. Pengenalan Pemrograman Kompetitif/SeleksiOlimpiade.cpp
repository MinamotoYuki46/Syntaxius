#include <bits/stdc++.h>
using namespace std;

struct player {
    string id;
    int score1, score2, score3;
};

bool compare(player a, player b) {
    if (a.score3 == b.score3) {
        if (a.score2 == b.score2) {
            return a.score1 > b.score1;
        }
        return a.score2 > b.score2;
    }
    return a.score3 > b.score3;
}

void solve() {
    int n, m;
    string targetPlayer;

    cin >> n >> m;
    cin >> targetPlayer;
    player p[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].score1 >> p[i].score2 >> p[i].score3;
    }
    sort(p, p + n, compare);

    for (int j = 0; j < m; j++) {
        if (targetPlayer == p[j].id) {
            cout << "YA" << endl;
            return;
        }
    }
    cout << "TIDAK" << endl;
}

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
    return 0;
}
