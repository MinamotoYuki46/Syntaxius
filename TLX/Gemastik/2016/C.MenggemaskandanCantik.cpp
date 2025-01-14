#include <bits/stdc++.h>
using namespace std;

struct gemastik {
    string nama;
    int gemas, cantik;
};

vector<gemastik> mhs, approved;
vector<int> score;

bool sortGemas(const gemastik& a, const gemastik& b) {
    return a.gemas < b.gemas;
}

bool sortCantik(const gemastik& a, const gemastik& b) {
    return a.cantik < b.cantik;
}


void solve() {
    vector<gemastik> resGemas = mhs; 
    vector<gemastik> resCantik = mhs; 
    sort(resGemas.begin(), resGemas.end(), sortGemas);
    sort(resCantik.begin(), resCantik.end(), sortCantik);

    vector<gemastik> topGemas, topCantik;
    copy(resGemas.end() - 3, resGemas.end(), back_inserter(topGemas));
    copy(resCantik.end() - 3, resCantik.end(), back_inserter(topCantik));

    



}

int main() {
    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        mhs.resize(n); // Resize mhs vector
        for (int i = 0; i < n; i++) {
            cin >> mhs[i].nama >> mhs[i].gemas >> mhs[i].cantik;
        }
        solve();
    }

    return 0;
}
