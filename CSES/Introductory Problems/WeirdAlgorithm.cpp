#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    printf("%lld ", n);

    while (n != 1){
        if (n % 2 == 0){
            n = n / 2;
            printf("%lld ", n);
        }
        else if (n % 2 == 1){
            n = 3*n + 1;
            printf("%lld ", n);
        }
        
    }
    return 0;
}