#include <bits/stdc++.h>
using namespace std;

int main(){
    string sequence;
    char current;
    int count = 0, answer = 0;
    cin >> sequence; 
    for(int i = 0; i < sequence.length();i++){
        if (sequence[i] != current){
            current = sequence[i];
            count = 0;
        }
        if (sequence[i] == current){
            count++;
        }
        answer = max(answer, count);
    }

    cout << answer << endl;

    return 0;
}