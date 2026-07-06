#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;

   
    int sum = 0;
    int result = 0;
    for (int j = 1; j <= log(n) / log(5); j++){
        result = n / pow(5, j);
        sum += result;
    }
    cout << sum << endl;
    
    return 0;
}