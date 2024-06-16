#include <bits/stdc++.h>
using namespace std;

int main(){
    string eq;
    cin >> eq;

    vector<char> num;
    vector<char> symbol;

    for(int i = 0; i < eq.size();i++){
        if(i % 2 == 0){
            num.push_back(eq[i]);
        }
        else{
            symbol.push_back(eq[i]);
        }
    }

    sort(num.begin(), num.end());

    for(int j = 0; j < num.size();j++){
        cout << num[j];
        if(j != num.size() - 1){
            cout << symbol[j];
        }
    }


    return 0;
}