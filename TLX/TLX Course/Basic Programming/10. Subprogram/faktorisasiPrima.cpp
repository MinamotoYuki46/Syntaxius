#include <bits/stdc++.h>
using namespace std;

int main(){
    int val;
    scanf("%d", &val);

    for (int i = 2; i <= val ; i++){
        int index = 0;
        while (val % i == 0){
            val /= i;
            index++;
        }
        if (index > 1){
            printf("%d^%d", i, index);
            if (val == 1){
                printf(" ");
            }
            else {
                printf("x ");
            }
        }
        else if (index == 1){
            printf("%d ", i);
            if (val == 1){
                printf(" ");
            }
            else {
                printf("x ");
            }
        }
    }
    return 0;
}