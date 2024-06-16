#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;

    while(testcase--){
        string word;
        cin >> word;

        for(int i = 0; i < ceil(word.length()/2) ; i +=2){
            cout << word[i];
        }
        cout << endl;
    }
    return 0;
}