#include <bits/stdc++.h>

using namespace std;

int main(){
    char s[101];
    scanf("%s", &s);

    int len = strlen(s);
    for (int i = 0; i < len;i++){
        int ord = int(s[i]);
        if (ord < 91){
            ord = ord + 32;
        }
        else if (ord > 96){
            ord = ord - 32;
        }
        s[i] = int(ord);
    }
    printf("%s", s);
    return 0;
}