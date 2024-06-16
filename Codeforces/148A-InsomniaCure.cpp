#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    //hit =  d - (d/k + d/l + d/m + d/n) + (d/lcm(k,l) + d/lcm(k,m) + d/lcm(k,n) + d/lcm(l,m) + d/lcm(l,n) + d/lcm(m,n)) - (d/lcm(lcm(k,l), m) + d/lcm(lcm(k,l), n) + d/lcm(lcm(l,m), n)) + (d/(lcm(lcm(lcm(k,l), m), n)));
    int count = d;
    if(k == 1 || l == 1 || m == 1 || n == 1)
    {
        cout << d << endl;
    }
    else
    {
        for(int i = 1; i <= d; i++)
        {
            if((i%k != 0) && (i%l != 0) && (i%m != 0) && (i%n != 0))
                count--;
        }
        cout << count << endl;
    }

    return 0;
}
