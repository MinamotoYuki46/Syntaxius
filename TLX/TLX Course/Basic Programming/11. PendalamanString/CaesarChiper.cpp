#include <bits/stdc++.h>

using namespace std;

int main(){
    char s[101];
    int n;
    scanf("%s %d", &s, &n);

    int len = strlen(s);
    for (int i = 0; i < len;i++){
        int ord = int(s[i] - 'a');
        int encrypted = (ord + n) % 26;
        s[i] = int(encrypted + 'a');
    }
    
    printf("%s", s);
    return 0;
}