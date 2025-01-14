#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main(){
    string s;
    cin >> s;
    int i = 0;
    
    if(s.find("_") != -1){
        while(1){
            if(s.find("_") != -1){
                int underscore = s.find("_");
                s[underscore + 1] = int(s[underscore +1] - 32);
                s = s.erase(underscore, 1);
            }
            else{
                break;
            }
        }
    }
    else{
        for (int i = 0; i < s.length(); i++){
            if (int(s[i]) < 97 ){
                s[i] = s[i] + 32;
                s.insert(i, "_");
            }
        }
    }
    cout << s;
}