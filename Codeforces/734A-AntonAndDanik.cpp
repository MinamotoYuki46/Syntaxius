#include <bits/stdc++.h>
using namespace std;

int main(){
    string comp;
    int n;
    cin >> n >> comp;

    map<char, int> count;
    for(int i = 0; i < n;i++){
        count[comp[i]]++;
    }
    if(count['A'] > count['D']){
        cout << "Anton";
    }
    else if (count['A'] < count['D']){
        cout << "Danik";
    }
    else{
        cout << "Friendship";
    }
    return 0;
}