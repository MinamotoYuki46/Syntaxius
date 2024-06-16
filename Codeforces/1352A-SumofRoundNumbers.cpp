#include <bits/stdc++.h>
using namespace std;

void solve(int num){
    int digit = 0, key = 0;
    map<int, int> count;

    while(num){
        count[digit] = num%10;
        if(count[digit] != 0){
            key++;
        }
        digit++;
        num /= 10;
    }
    cout << key << endl;

    for(int i = 0; i < digit; i++){
        if(count[i] != 0){
            cout << pow(10, i) * count[i] << " ";
        }

    }
    cout << endl;

}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}