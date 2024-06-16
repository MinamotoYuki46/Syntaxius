#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    int a[17] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    for (i =0;i<=16;i++){
        if (a[i] == log2(n)){
                cout << "Ya" <<endl;
                break;}
    }
    if (a[i] != log2(n))
         cout << "bukan" << endl;
}