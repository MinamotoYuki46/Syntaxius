#include <stdio.h>

int main(){
    int hasil;
    int testcase;
    scanf("%d", &testcase);
    for (int i = 1; i <= testcase; i++){
        int nilai;
        scanf("%d", &nilai);
        hasil += nilai;
    }
    printf("%d",hasil);
}