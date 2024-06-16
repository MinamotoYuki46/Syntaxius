#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int dimension[2*t];

    for (int i = 0; i < t; i++){
        cin >> dimension[0+2*i] >> dimension[1 + 2*i]; 
    }

    for(int i = 0; i < t; i++){
        for (int j = 0; j < dimension[0+2*i] ; j++){
            for(int k = 0; k < dimension[1 + 2*i]; k++){
                if (dimension[0 + 2*i] < 3 || dimension[1 + 2*i] < 3){
                    cout << "*";
                }
                else if (j == 0 || j == dimension[0 + 2*i] - 1 || k == 0 || k == dimension[1 + 2*i] - 1){
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