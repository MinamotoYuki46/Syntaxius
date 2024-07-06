#include <iostream>
#include <vector>
using namespace std;

bool isBeautiful(const vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            if (i + 1 < n && j + 1 < m) {
                int ones = matrix[i][j] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
                if (ones % 2 == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int minChangesToBeautiful(vector<vector<int>>& matrix, int n, int m) {
    int changes = 0;
    for (int i = 0; i < n - 1; i += 2) {
        for (int j = 0; j < m - 1; j += 2) {
            int ones = matrix[i][j] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
            if (ones % 2 == 0) {
                // Temukan elemen yang paling mudah diubah untuk menghasilkan jumlah satu ganjil
                if (ones == 0 || ones == 4) {
                    matrix[i][j] = 1 - matrix[i][j]; // ubah satu elemen 0 ke 1 atau 1 ke 0
                    changes++;
                } else if (ones == 2) {
                    int flip = 1; // jika dua elemen 1, ubah salah satu 1 ke 0 atau salah satu 0 ke 1
                    for (int x = 0; x < 2; ++x) {
                        for (int y = 0; y < 2; ++y) {
                            if (matrix[i + x][j + y] == 0) {
                                matrix[i + x][j + y] = 1;
                                changes++;
                                flip = 0;
                                break;
                            }
                        }
                        if (!flip) break;
                    }
                    if (flip) { // jika tidak ada 0 untuk diubah ke 1, ubah 1 ke 0
                        for (int x = 0; x < 2; ++x) {
                            for (int y = 0; y < 2; ++y) {
                                if (matrix[i + x][j + y] == 1) {
                                    matrix[i + x][j + y] = 0;
                                    changes++;
                                    break;
                                }
                            }
                            if (flip) break;
                        }
                    }
                }
            }
        }
    }
    return changes;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    if (isBeautiful(matrix, n, m)) {
        cout << "Matrix is already beautiful" << endl;
    } else {
        int changes = minChangesToBeautiful(matrix, n, m);
        cout << "Minimum changes needed: " << changes << endl;
    }

    return 0;
}
