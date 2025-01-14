#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    int arrA[101][101];
    int arrB[101][101];
    int arrC[101][101];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arrA[i][j]);
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int k = 1; k <= p; k++) {
            scanf("%d", &arrB[j][k]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= p; k++) {
            int result = 0;
            for (int j = 1; j <= m; j++) {
                result = result + arrA[i][j] * arrB[j][k];
            }
            printf("%d ", result);
        }
        printf("\n");
    }

    return 0;
}
