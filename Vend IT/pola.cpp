#include <iostream>

using namespace std;

int main(){
    int h, i, j, k;
    cin >> h;
    k = 0;

    for (i = 0; i<h; ++i){
        for (j = 0; j <=i; j++){
            cout<< k % 10;
            k++;
        }
        
        cout << endl;
    } 
}