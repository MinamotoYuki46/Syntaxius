#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int lt = t.length();

    while(1){
        if (s.find(t) != -1){
            s = s.erase(s.find(t), lt);
        }
        else{
            break;
        }
    }
    cout << s;
}