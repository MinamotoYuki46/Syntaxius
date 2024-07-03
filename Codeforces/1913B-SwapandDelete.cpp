#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;


int check(string& t, string& s){
    int sum = 0;
    string temp;
    bool checks = false;
    for(int i = 0; i < t.size(); ++i){
        if(t[i] != s[i]){
            sum++;
            checks = true;
        } 
        else temp+= t[i];
    }

    if(checks) sum+= check(temp, s);
    return sum;
}

void solve(){
    string s;
    cin >> s;
    if(s.size() == 1){
        cout <<"1\n";
        return;
    }

    int one = 0;
    int zer = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1') one++;
        else zer++;
    }

    int cnt = 0; 
    string t;
    if(one > zer){
        cnt += one - zer;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1' && zer > 0){
                t+=s[i];
                zer--;
            }
            else if(s[i] == '0') t+= s[i];
        }
    }
    else if(zer > one){
        cnt+= zer - one;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '0' && one > 0){
                t+=s[i];
                one--;
            }
            else if(s[i] == '1') t+= s[i];
        }
    }
    cnt+=check(t, s);
    cout <<cnt<<"\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test; cin >> test;
    for(int i =  1; i <= test; ++i){
        solve();
    }
    return 0;
}