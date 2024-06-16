#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double volume[n], total = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> volume[i];
        total += volume[i];
    }

    printf("%.12llf", (total/double(n)));
    return 0;
}