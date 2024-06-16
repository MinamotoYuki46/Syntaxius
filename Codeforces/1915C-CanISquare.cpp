#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    
    for(int j =0 ; j < testcase; j++) {
        long long int num, input;
        cin >> num;
        long long int result = 0;
        for(int i = 0; i < num ; i++){
            cin >> input;
            result += input;
        }
        if(sqrt(result) == round(sqrt(result))){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}