#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    if(int(str[0]) >90){
        str[0] = int(str[0]) - 32; 
    }
    cout << str;

    return 0;
}