#include <iostream>
using namespace std;

int a[3][3];

int main(){
    //input matrix value
    for (int i = 0; i <3; i++){
        for (int j = 0; j < 3; j++){
          cin >> a[i][j];

        }
    }

    //print matrix transpose
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}