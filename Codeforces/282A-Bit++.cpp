#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 0, testcase;
    string input;
    cin >> testcase;
    
    for(int i = 0;i < testcase;i++){
        cin >> input;
        if (input[1] == '+' ){
            ++x;
        }
        else if(input[1] == '-'){
            --x;
        }
        

    }
    cout << x << endl;

    return 0;
}