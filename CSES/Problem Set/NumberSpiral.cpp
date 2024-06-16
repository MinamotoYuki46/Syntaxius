#include <bits/stdc++.h>
using namespace std;

long long numberSpiral(long long row, long long column){
    long long dif = abs(row-column), pivot = max(row, column);

    if (row == column){
        return 1 + ((row - 1) * (2 * 2 + (row - 2)*2) /2);
    }

    else if(pivot % 2 == 0){
        if (row < pivot){
            return numberSpiral(pivot, pivot) - dif;
        }
        else if (column < pivot ) {
            return numberSpiral(pivot, pivot) + dif;
        }
        
    }
    else if(pivot % 2 == 1){
        if (row < pivot){
            return numberSpiral(pivot, pivot) + dif;
        }
        else if (column < pivot ){
            return numberSpiral(pivot, pivot) - dif;
        }
    }

}


int main(){
    int testcase;
    cin >> testcase;
    long long r, c;
    while (testcase--){
        cin >> r >> c;
        cout << numberSpiral(r, c) << endl;
    }

    return 0;
}