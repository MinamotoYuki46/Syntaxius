#include <bits/stdc++.h>
using namespace std;
int main() {
    int range, val, min. max;
    scanf("%d", &range);
    for (int i = 0; i < range;i++){
        scanf("%d", &val);

        if (i == 0){
            min = val;
            max = val;
        }
        else {
            if (val > max){
                max = val;
            }
            if (val < min){
                min = val;
            }
        }
    }
    printf("%d %d", max, min);
}