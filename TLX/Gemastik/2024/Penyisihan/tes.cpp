#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long num = ((1ULL) << 33) - 1ULL; 

    num = num ^ (1ULL << 31);
    cout << num << endl;

    return 0;
}