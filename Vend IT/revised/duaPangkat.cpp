#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;

    if (pow(2, round(log2(num))) == num){
        cout << "Ya";
    }
    else{
        cout << "Tidak";
    }
    return 0;
}