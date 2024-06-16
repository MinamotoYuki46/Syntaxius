#include <bits/stdc++.h>
using namespace std;

int solve(int num){
    if (num&1){
        return num / 2;
    }
    else{
        return (num - 1) /2;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}