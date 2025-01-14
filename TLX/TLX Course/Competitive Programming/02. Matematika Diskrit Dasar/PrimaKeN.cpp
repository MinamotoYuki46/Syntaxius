#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void primeGenerator(){
    int flag = 0;
    for (int i = 1 ; i < 1000000; i++){
        flag = 0;
        for(int j = 2; j <= sqrt(i) ; j++){
            if (i % j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0 && i != 1){
            prime.push_back(i);
        }
    }
}

int main(){
    int testcase, n;
    cin >> testcase;
    primeGenerator();
    while (testcase--){
        cin >> n;
        cout << prime[n-1] << endl;
    }
}