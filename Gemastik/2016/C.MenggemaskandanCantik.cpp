#include <bits/stdc++.h>
using namespace std;

struct gemastik {
    string nama;
    int gemas, cantik;
};

vector<gemastik> mhs;

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
