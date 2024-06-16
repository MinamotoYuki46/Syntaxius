#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    string str;

    while(testcase--){
        cin >> str;
        stack<char> RPN;
        int len = str.length();

        for(int i = 0; i < len;i++){
            if (str[i] == '('){
                RPN.push(str[i]);
            }
            else if(str[i] == ')'){
                char x = RPN.top();
                RPN.pop();
                RPN.pop();
                cout << x;
            }
            else if(isalnum(str[i])){
                cout << str[i];
            }
            else{
                RPN.push(str[i]);
            }
        }
        cout << endl;
    }

    return 0;
}