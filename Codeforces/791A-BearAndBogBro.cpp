#include <iostream>
using namespace std;

int main(){
    int a, b, year;
    cin >> a >> b;

    while(a <= b){
        a *= 3;
        b *= 2;
        year++;
    }
    cout << year;

    return 0;
}