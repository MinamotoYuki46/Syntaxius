#include <bits/stdc++.h>
using namespace std;

struct point{
    int row, column, fill;
};



int main(){
    int t;
    cin >> t;
    point p[t];

    for (int i = 0; i < t; i++){
        cin >> p[i].row >> p[i].column >> p[i].fill;
    }

    for(int i = 0; i < t; i++){
        for (int j = 0; j < p[i].row * (p[i].fill + 1) + 1 ; j++){
            for(int k = 0; k < p[i].column * (p[i].fill + 1) + 1; k++){
                if ((j % (p[i].fill + 1) != 0 && k % (p[i].fill + 1) != 0) && (j % (p[i].fill * 2 + 2) ==  k % (p[i].fill*2 + 2))){
                    cout << "\\";
                }
                else if ((j % (p[i].fill + 1) != 0 && k % (p[i].fill + 1) != 0) && ((j+k)  % (p[i].fill * 2 + 2) == 0)){
                    cout << "/";
                }
                else {
                    cout << ".";
                }
            }
        cout << endl;
        }
    cout << endl;
    }
    return 0;
}