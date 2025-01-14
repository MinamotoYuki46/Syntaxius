#include <bits/stdc++.h>
using namespace std;

int main(){
    int val, testcase, flag = 0;
    scanf("%d", &testcase);

    while(testcase--){
        scanf("%d", &val);

        if (val == 1 || val == 2 || val == 3){
            printf("YA\n");
        }
        else if (val >= 4){
            flag = 2;
            for (int i = 2; i <= sqrt(val); i++){
                if (val % i == 0){
                    flag += 2;
                }
            }

            if (flag > 4){
                printf("BUKAN\n");
            }
            else {
                printf("YA\n");
            }
        }
    }

    return 0;
}