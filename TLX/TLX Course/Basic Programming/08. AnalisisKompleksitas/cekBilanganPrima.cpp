#include <bits/stdc++.h>
using namespace std;

int main(){
    int val, testcase, flag = 0;
    scanf("%d", &testcase);

    while(testcase--){
        scanf("%d", &val);

        if (val == 0 || val == 1){
            printf("BUKAN\n");
        }
        else if (val == 2 || val == 3){
            printf("YA\n");
        }
        else{
            flag = 0;
            for (int i = 2; i <= sqrt(val); i++){
                if (val % i == 0){
                    flag = 1;
                    break;
                }
            }

            if (flag != 0){
                printf("BUKAN\n");
            }
            else if (flag == 0){
                printf("YA\n");
            }
        }
    }

    return 0;
}