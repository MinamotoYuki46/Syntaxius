#include <bits/stdc++.h>
using namespace std;
int main() {
    int val, result;
    scanf( "%d", &val);
    for (int i = 1; i < val; i++){
        result = val % i;
         if (result ==0){
            printf("%d \n", val / i);
         }
    }
}   