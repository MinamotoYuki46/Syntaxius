#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;

    int bill = k * (w * (w+1) / 2);

    if(n >= bill){
        cout << 0;
    } 
    else{
        cout << bill - n;
    }
    return 0;
}