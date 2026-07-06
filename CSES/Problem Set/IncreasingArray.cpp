#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, moves = 0;
    cin >> n;
    long long array[n];
    
    for(int i = 0; i < n;i++){
        cin >> array[i];
    }

    for(int i = 1; i < n ; i++){
        if (array[i] < array[i - 1]){
            moves += (array[i - 1] - array[i]);
            array[i] = array[i-1];
        }
    }
    
    cout << moves;

    return 0;
}