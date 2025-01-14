#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;

    while(tc--){
        int box; cin >> box;
        int arr[box][3];
        int maks = 0;
        int minim = 0;
        for(int i = 0; i < box; ++i){
            int temp1 = INT_MAX;
            int temp2 = INT_MIN;
            for(int j = 0; j < 3; ++j){
                cin >> arr[i][j];
                temp1 = min(temp1, arr[i][j]);
                temp2 = max(temp2, arr[i][j]);
            }
            minim += temp1;
            maks += temp2;
        }
        cout << minim <<" " << maks<<endl;

    }
    return 0;
}

