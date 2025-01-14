#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double n;
    
    cin >> n;

    int m = n;
    int o = n;

    if (n >  0 && n != m){
        o = m + 1;
    }
    else if (n <  0 && n != m){
        m = o - 1 ;

    }
    cout << m << " " << o << endl;
}