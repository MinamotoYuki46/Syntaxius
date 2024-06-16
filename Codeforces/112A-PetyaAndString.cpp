#include <bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    int status = 0;
    cin >> str1 >> str2;

    for(int i = 0; i < str1.size();i++){
        if (int(str1[i]) <= 90){
            str1[i] = int(str1[i] + 32);
        }
        if (int(str2[i]) <= 90){
            str2[i] = int(str2[i] + 32);
        }



        
        if (str1[i] < str2[i]){
            status = -1;
            break;
        }
        else if (str1[i] > str2[i]){
            status = 1;
            break;
        }
    }
    cout << status;

    return 0;
}