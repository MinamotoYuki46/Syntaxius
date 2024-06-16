#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase, result;
    cin >> testcase;
    int number[testcase];

    for(int i = 0; i < testcase; i++){
        int sum = 0;
        cin >> number[i];
        for (int j = 1; j < log(number[i]) / log(5); j++){
            result = number[i] / pow(5, j);
            sum += result;
        }
        cout << sum << endl;
    }

    return 0;
}