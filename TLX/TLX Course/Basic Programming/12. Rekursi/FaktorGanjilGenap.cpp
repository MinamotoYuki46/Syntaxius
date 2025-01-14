#include <bits/stdc++.h>

using namespace std;

int factorial(int x){
    if (x == 1){
        return 1;
    }
    else if (x % 2 == 0){
        return x / 2 * factorial(x-1); 
    }
    else {
        return x * factorial(x -1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}