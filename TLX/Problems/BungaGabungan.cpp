#include <bits/stdc++.h>
using namespace std;

int main(){
    int P, Q;
    scanf("%d %d", &P, &Q);

    int flower = P*P + Q*Q + 1;

    if(flower % 4 == 0){
        printf("%d", flower/4);
    }
    else{
        printf("%d", -1);
    }
}