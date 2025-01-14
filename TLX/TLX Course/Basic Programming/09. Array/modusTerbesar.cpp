#include <bits/stdc++.h>
using namespace std;

int main() {
    int range, array[100001], modes[1001] = {0};
    scanf("%d", &range);
    
    for (int i = 1; i <= range; i++){
        scanf("%d\n", &array[range]);
        int temp = array[range];
        modes[temp]++;
    }

    int max = -1, index = -1;

    for(int i = 0 ; i <= 1000; i++){
        if (modes[i] >= max){
            max = modes[i];
            index = i;
        }
    }
    printf ("%d", index);
}