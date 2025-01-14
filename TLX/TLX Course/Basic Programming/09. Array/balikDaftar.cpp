#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, arr[105];
    while (scanf("%d", &arr[n]) != EOF){
        n++;
    }
    for (int i = n -1 ; i >= 0; i--){
        printf("%d\n", arr[i]);
    }
}