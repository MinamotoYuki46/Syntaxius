#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[101][101];

    for (int i = 1; i <=n; i++){
        for (int j = 1 ; j <= m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
        
    for(int j = 1 ; j <= m; j++){
        for(int i = n; i > 0; i--){
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}