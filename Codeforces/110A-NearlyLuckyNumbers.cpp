#include <bits/stdc++.h>
using namespace std;

int main(){
    string num;
    int lucky = 0;
    cin >> num;

    for(int i = 0; i < num.size();i++){
        if(num[i] == '4' || num[i] == '7'){
            lucky++;
        }
    }

    if(lucky == 4 || lucky == 7){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}