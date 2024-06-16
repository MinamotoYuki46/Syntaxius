#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, minimum, rem;
    cin >> a >> b;

    minimum = min(a,b);
    rem = max(a,b) - minimum;

    cout << minimum << " " << rem/2;

    return 0;
}