#include <bits/stdc++.h>

using namespace std;
void gunung(int x);

int main(){
    int n;
    scanf("%d", &n);
    gunung(n);

}

void gunung(int x){
    if (x > 0){
        gunung(x -1);
        for (int i = 0; i < x;i++){
            printf("*");
        }
        printf("\n");
        gunung(x-1);
    }
}
