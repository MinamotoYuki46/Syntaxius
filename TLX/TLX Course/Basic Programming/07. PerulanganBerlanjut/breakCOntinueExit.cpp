#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        if (i % 10 == 0){
            continue;}
        if (i == 42){
            printf("ERROR");
            break;}
        printf("%d\n", i);
    }
}