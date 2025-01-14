#include <bits/stdc++.h>
using namespace std;

char quad[128*128][128];
int m[128][128], str_len;
string s;

void reverse(int r, int c, int k){
    for (int i = r; i < r + k; i++){
        for (int j = c ; j < c + k; j++) {
            m[i][j] = 1;
        }
    }
}

void quadtree(int idx, int r, int c, int k){
    if (idx + 1 >= str_len){
        reverse(r, c, k);
    }
    else{
        switch(s[idx + 1]){
            case '0' : quadtree(idx+1, r, c, k/2); break;
            case '1' : quadtree(idx+1, r, c + (k/2), k/2); break;
            case '2' : quadtree(idx+1, r + (k/2), c, k/2); break;
            case '3' : quadtree(idx+1, r + (k/2), c + (k/2), k/2); break;
        }
    }
}

int main(){
    int result;
    scanf("%d", &result);
    for (int i = 0; i < result; i++){
        scanf("%s", &quad[i]);
    }

    int r, c;
    scanf("%d %d", &r, &c);

    int msize = 1;
    while (msize < r || msize < c){
        msize *= 2;
    }

    for (int i = 0 ; i < result ; i++){
        s = quad[i];
        str_len = s.length();
        quadtree(0, 0, 0, msize);
    }

    for (int i = 0; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}