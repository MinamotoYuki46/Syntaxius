#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(int(str[i]) <= 90){
            str[i] = int(str[i]) + 32;
        }
        else{
            str[i] = int(str[i])- 32;
        }
    }

    cout << str;
}