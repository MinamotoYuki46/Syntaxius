#include <bits/stdc++.h>

using namespace std;

int func(int a, int b, int x, int k){
    if (k == 0){
        return x;
    }
    else {
        return abs(a * func(a, b, x, k -1) + b);
    }
}

int main(){
    int a, b, k, x;
    scanf("%d %d %d %d", &a, &b, &k, &x);
    printf("%d", func(a, b, x, k));
    return 0;
}