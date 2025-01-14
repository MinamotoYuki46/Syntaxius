#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, sum, avg, key;
    cin >> t;
    int boba[t];
    vector<int> index; 
    
    for(int i = 0; i < t;i++){
        cin >> boba[i];
        sum += boba[i];
    }
    avg = sum / t;

    for(int i = 0; i < t;i++){
        if (boba[i] != avg){
            key++;
            index.push_back(i);
        }
    }
    if(key == 2){
        int diff, init, target;
        if(boba[index[0]] - boba[index[1]] < 0){
            init = index[1] + 1;
            target = index[0] + 1;
        }
        else{
            init = index[0] + 1;
            target = index[1] + 1;
        }
        
        diff = abs(boba[index[0]] - boba[index[1]]) / 2;

        cout << diff << " " << init << " " << target;
    }
    else if (key == 0){
        cout << "SESUAI";
    }
    else{
        cout << "TIDAK SESUAI";
    }
    




    return 0;
}