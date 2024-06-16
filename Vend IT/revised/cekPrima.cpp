#include <bits/stdc++.h>
using namespace std;

void isPrime(int num){
    bool flag = false;
    if (num == 1 || num == 0){
        cout << "BUKAN";
    }
    else if(num == 2 || num == 3){
        cout << "YA";
    }
    else{
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                flag = true;
                break;
            }

        }
        flag == false ? cout << "YA" : cout << "BUKAN";
    }
}

int main(){
    int t, num;
    cin >> t;

    while(t--){
        cin >> num;
        isPrime(num);
        cout << "\n";
    }

    return 0;
}