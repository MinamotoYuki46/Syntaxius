#include <bits/stdc++.h>
using namespace std;


int catat[1000];
bool pernah[1000];
int n;


void tulis(int depth){
    if (depth >= n){
        bool zigzag = true;
        for (int i = 1; i < n-1; i++){
            if (!((catat[i] > catat[i+1] && catat[i] > catat[i-1]) || (catat[i] < catat[i+1] && catat[i] < catat[i-1]))){
                zigzag = false;
            }
        }
        if (zigzag){
            for (int i = 0; i < n;i++){
                printf("%d", catat[i]);
            }
            printf("\n");
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            if (!pernah[i]){
                pernah[i] = true;
                catat[depth] = i;
                tulis(depth + 1);
                pernah[i] = false;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    tulis(0);


    return 0;
}

/*
3
1 < 3 > 2
2 > 1 < 3
2 < 3 > 1
3 > 1 < 2

4
1 < 3 > 2 < 4
1 < 4 > 2 < 3
2 > 1 < 4 < 3
2 < 3 > 1 < 4
2 < 4 > 1 < 3
3 > 1 < 4 > 2
3 > 2 < 4 > 1
3 < 4 > 1 < 2
4 > 1 < 3 > 2
4 > 2 < 3 > 1
*/