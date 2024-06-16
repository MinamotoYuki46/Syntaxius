#include <stdio.h>

int reverse(int x){ 
    int temp = x;
    int ret = 0;

    while (temp>0){
        ret = (ret* 10) + (temp % 10);
        temp /= 10;
    }
    return ret;}

int main(){
    int testcase;
    scanf("%d", &testcase);

    while(t--){
        
    }

    return 0;
}