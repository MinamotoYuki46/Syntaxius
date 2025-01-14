#include <bits/stdc++.h>
using namespace std;
int main() {
    int nilai;
    scanf("%d", &nilai);
    while(nilai % 2 == 0){
        nilai = nilai / 2;
    }
    if (nilai == 1){
        printf( "ya" ) ;
    }
    else {
        printf( "bukan" ) ;
    }
}