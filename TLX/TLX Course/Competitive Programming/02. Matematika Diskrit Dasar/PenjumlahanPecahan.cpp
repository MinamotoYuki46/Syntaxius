#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y){
    if (y == 0){
        return x;
    }
    else {
        return gcd(y, x%y);
    }
}

int main(){
    long long a, b, c, d, e, f, h;
    cin >> a >> b >> c >> d;
    f = b * d / gcd(b,d);
    e = f / b * a + f / d * c;
    h = gcd(e, f);
    cout << e / h << " " << f / h<< endl;
    return 0;
}