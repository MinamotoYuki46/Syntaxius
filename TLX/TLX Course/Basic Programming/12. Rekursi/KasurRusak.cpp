#include <bits/stdc++.h>

using namespace std;

bool palindrome(string s){
    int len = s.size();
    if (len == 1){
        return true;
    }
    else if (len == 2){
        return s[0] == s[1];   
    }
    else {
        return s[0] == s[len -1] && palindrome(s.substr(1, len -2));
    }
}

int main(){
    string s;
    cin >> s;
    if (palindrome(s)){
        printf("YA");
    }
    else {
        printf("BUKAN");
    }
    
    return 0;
}