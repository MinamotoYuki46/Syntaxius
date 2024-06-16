#include <bits/stdc++.h>
using namespace std;

void nhaySolve(int len, string needle, string haystack){
    if(len > haystack.length()){
        return;
    }
    else if( needle == haystack){
        cout << 0 << endl;
    }

    else{
        for(int i = 0; i < 1 + (haystack.length() - len) ;i++){
            if (needle == haystack.substr(i, len)){
                cout << i << endl;
            }
        }
    }
     
}

int main(){
    int lenNeedle;
    string needle, haystack;

    while(cin >> lenNeedle >> needle >> haystack){
        nhaySolve(lenNeedle, needle, haystack);
        cout << endl;

    }

    return 0;
}