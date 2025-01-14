#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a, b;
    double area;
    cin >> a >> b;
    area =  (.5) *a*b;

    cout << fixed << setprecision(2) << area << endl;
}