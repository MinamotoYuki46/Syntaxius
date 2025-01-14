#include <bits/stdc++.h>
using namespace std;

int main(){
    int val;
    cin >> val;
    int dup;

    dup = pow(round(sqrt(val)), 2);
    if (val == dup){
        cout << round(sqrt(val)) << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}