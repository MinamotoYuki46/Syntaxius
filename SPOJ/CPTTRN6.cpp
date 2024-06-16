#include <bits/stdc++.h>
using namespace std;

struct point{
    int row, column, heigth, width;
};

int main(){
    int t;
    cin >> t;
    point p[t];

    for (int i = 0; i < t; i++){
        cin >> p[i].row >> p[i].column >> p[i].heigth >> p[i].width;
    }

    for(int i = 0; i < t; i++){
        for (int j = 0; j < p[i].row + (1 + p[i].row)*p[i].heigth ; j++){
            for(int k = 0; k < p[i].column + (1 + p[i].column) * p[i].width; k++){
                if (j % (p[i].heigth + 1) == p[i].heigth && k % (p[i].width + 1) != p[i].width){
                    cout << "-";
                }
                else if (j % (p[i].heigth + 1) != p[i].heigth && k % (p[i].width + 1) == p[i].width){
                    cout << "|";
                }
                else if (j % (p[i].heigth + 1) == p[i].heigth && k % (p[i].width + 1) == p[i].width){
                    cout << "+";
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