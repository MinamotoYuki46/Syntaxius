#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    long long sum = 0, series = n * (n+1) / 2;
    long long val;

    for(long long i = 0; i < n - 1;i++){
        scanf("%lld", &val);
        sum += val;
    }
    printf("%lld", series  - sum);

    return 0;
}