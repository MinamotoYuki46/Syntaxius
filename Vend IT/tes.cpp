#include <iostream>
using namespace std;



int main(){
    //input matrix value
    int n,m;
    cin >> n >> m ;
    int a[n][m];

    for (int i = 0; i <n; i++){
        for (int j = 0; j < m; j++){
          cin >> a[i][j];

        }
    }

    //print matrix transpose
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}