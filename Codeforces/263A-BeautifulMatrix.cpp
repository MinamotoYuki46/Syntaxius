#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, arr[5][5];

    for(int i = 0; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> arr[i][j];

            if(arr[i][j] == 1){
                x = j;
                y = i;
            }
        }
    }

    cout << abs(2 - x) + abs(2 - y) << endl;
    return 0;
}