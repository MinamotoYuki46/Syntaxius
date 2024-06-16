#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, problems = 0;
    cin >> n >> k;

    int deadline = 240 - k;

    for(int i = 1; i <= n ; i++){
        if(deadline - 5 * i * (i+1) / 2 >= 0){
            problems++;
        }
        else{
            break;
        }
    }
    cout << problems;
    return 0;
}