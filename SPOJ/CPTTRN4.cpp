#include <bits/stdc++.h>
using namespace std;

bool XNOR(bool a, bool b){
    return (a && b) || (!a && !b);
}

int main(){
    int t;
    cin >> t;
    int dimension[4*t];

    for (int i = 0; i < t; i++){
        cin >> dimension[0+4*i] >> dimension[1 + 4*i] >> dimension[2 + 4*i] >> dimension[3 + 4*i]; 
    }

    for(int i = 0; i < t; i++){
        for (int j = 0; j < dimension[0+4*i]*(1 + dimension[2+ 4*i]) + 1 ; j++){
            for(int k = 0; k < dimension[1 + 4*i]*(1 + dimension[3 + 4*i]) + 1; k++){
                if (j % (dimension[2 + 4*i] + 1) == 0 || k % (dimension[3 + 4*i] + 1 ) == 0){
                    cout << "*";
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