#include <bits/stdc++.h>
using namespace std;

double eq(int num){
    return (num * (num+1) * (num+2))/6;
}

int main(){
    double n;
    cin >> n;
    int level = 1;

    while(true){
        if (n - eq(level) < 0){
            break;
        }
        level++;
    }
    cout << level - 1;

    return 0;
}