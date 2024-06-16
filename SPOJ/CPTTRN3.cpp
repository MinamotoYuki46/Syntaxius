#include <bits/stdc++.h>
using namespace std;

bool XNOR(bool a, bool b){
    return (a && b) || (!a && !b);
}

int main(){
    int t;
    cin >> t;
    int dimension[2*t];

    for (int i = 0; i < t; i++){
        cin >> dimension[0+2*i] >> dimension[1 + 2*i]; 
    }

    for(int i = 0; i < t; i++){
        for (int j = 0; j < 3*dimension[0+2*i] + 1 ; j++){
            for(int k = 0; k < 3*dimension[1 + 2*i] + 1; k++){
                if (j % 3 == 0 || k % 3 == 0){
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