#include<bits/stdc++.h>
using namespace std;

int main(){
    int year, temp, rem;
    cin >> year;

    while(true){
        year++;
        map<int, int> distinct;
        temp = year;

        while(temp){
            rem = temp % 10;
            distinct[rem]++;
            temp /= 10;
        }
        if(distinct.size() == floor(1 + log10(year))){
            break;
        }

    }
    cout << year;
    
    return 0;
}