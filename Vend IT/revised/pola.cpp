#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, val = 0;
    cin >> num;

    for(int i = 0; i < num; i++){
        for(int j = 0; j <= i; j++){
            cout << val % 10;
            val++;
        }
        cout << "\n";
    }
    return 0;
}