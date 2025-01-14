#include <bits/stdc++.h>
using namespace std;

int fx(int A, int B, int x){
    return abs(A * x + B);
}

int main(){
    int A, B, K, x;
    scanf("%d %d %d %d", &A, &B, &K, &x);

    for (int i = 0 ; i < K; i++){
        x = fx(A, B, x);
    }
    printf("%d", x);
    return 0;
}