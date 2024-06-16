#include <bits/stdc++.h>
using namespace std;

int main(){
    int target, step = 0;
    cin >> target;

    while(target){
        if(target - 5 >= 0){
            target -= 5;
        }
        else if(target - 4 >= 0){
            target -= 4;
        }
        else if(target - 3 >= 0){
            target -= 3;
        }
        else if(target - 2 >= 0){
            target -= 2;
        }
        else if(target - 1 >= 0){
            target -= 1;
        }
        step++;
    }
    cout << step;
    return 0; 
}