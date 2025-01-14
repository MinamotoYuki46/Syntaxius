#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        cout <<  (n - 1) * (2 * 2 + (n - 2) * 2) / 2 << endl;
    }
    return 0;
}