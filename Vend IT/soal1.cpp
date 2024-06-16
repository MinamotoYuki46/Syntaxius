#include <iostream>

using namespace std;

int main(){
    int n, m, i , j;
    int a[n][m];
    cin >> n >> m;

    //input matrix value
    for (int i = 0; i <m; i++){
        for (int j = 0; j < n; j++){
          cin >> a[i][j];

        }
    }

    //print matrix transpose
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j] << " ";
        }
        
    }
}