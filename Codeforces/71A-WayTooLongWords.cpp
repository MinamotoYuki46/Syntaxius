#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;

    cin >> testcase;

    while(testcase--){
        string words;
        cin >> words;

        if(words.length() > 10){
            cout << words[0] << words.length() - 2 << words[words.length() - 1] << endl;
        }
        else{
            cout << words << endl;
        }
    }


    return 0;
}