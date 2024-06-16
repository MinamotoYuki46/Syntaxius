#include <bits/stdc++.h>
using namespace std;

struct point{
    int row, column, diamond;
};

int mod(int a, int b) {
    int result = a - (b * floor(a / static_cast<double>(b)));
    return (result + b) % b;
}

int main(){
    int t;
    cin >> t;
    point p[t];

    for (int i = 0; i < t; i++){
        cin >> p[i].row >> p[i].column >> p[i].diamond;
    }

    for(int i = 0; i < t; i++){
        for (int j = 0; j < p[i].row * 2 * p[i].diamond ; j++){
            for(int k = 0; k < p[i].column * 2 * p[i].diamond; k++){
                if (k % (p[i].diamond * 2) == mod( (p[i].diamond - (1 + j)),(p[i].diamond * 2))){
                    cout << "/";
                }
                else if (k % (p[i].diamond * 2) == (p[i].diamond + j) % (p[i].diamond * 2)){
                    cout << "\\";
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