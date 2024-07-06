#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwapsToSort(string S, string M) {
    int n = S.length();
    
    // Membuat vektor dari pasangan (karakter, posisi) untuk kedua string
    vector<pair<char, int>> S_pos(n);
    vector<pair<char, int>> M_pos(n);
    
    for (int i = 0; i < n; i++) {
        S_pos[i] = make_pair(S[i], i);
        M_pos[i] = make_pair(M[i], i);
    }
    
    // Urutkan berdasarkan karakter
    sort(S_pos.begin(), S_pos.end());
    sort(M_pos.begin(), M_pos.end());
    
    // Membuat array visited untuk menandai elemen yang sudah di swap
    vector<bool> visited(n, false);
    
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        // Jika sudah di swap atau sudah di posisi yang benar
        if (visited[i] || S_pos[i].second == M_pos[i].second) {
            continue;
        }
        
        // Hitung siklus ukuran
        int cycle_size = 0;
        int x = i;
        while (!visited[x]) {
            visited[x] = true;
            // Gerak ke elemen berikutnya
            x = M_pos[x].second;
            cycle_size++;
        }
        
        // Jika siklus lebih dari 1, tambahkan swaps
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }
    
    return swaps;
}

int main() {
    string S = "abeee";
    string M = "aeeeb";
    cout << minSwapsToSort(S, M) << endl;  // Output: 3
    return 0;
}
