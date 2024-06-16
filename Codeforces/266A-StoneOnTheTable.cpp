#include <bits/stdc++.h>
using namespace std;

int consecutive(int num, string str){
    int count;

    for(int i = 0; i < num; i++){
        if (str[i] == str[i-1]){
            count++;
        }
    }
    return count;
}


int main(){
    string stone;
    int n;
    cin >> n >> stone;
    cout << consecutive(n, stone);

    return 0;
}