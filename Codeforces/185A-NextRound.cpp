#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, flag = 0;
    cin >> n >> k;
    int t[n];
    
    
    for(int i = 0; i < n ; i++){
        cin >> t[i];
    }

    for(int j = 0; j < n ; j++){
        if (t[j] == 0){
            continue;
        }
        else if (t[j] >= t[k-1]){
            flag++;
        }
    }
    cout << flag << endl;
    return 0;
}