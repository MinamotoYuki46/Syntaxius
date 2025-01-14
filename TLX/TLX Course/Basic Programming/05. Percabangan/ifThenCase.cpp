#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if ((0 <= n) && (n < 10 )){
        cout << "satuan" << endl;
    }
    else if ((10 <= n) && (n < 100 )){
        cout << "puluhan" << endl;
    }
    else if ((100 <= n) && (n < 1000 )){
        cout << "ratusan" << endl;
    }
    else if ((1000 <= n) && (n < 10000 )){
        cout << "ribuan" << endl;
    }
     else if ((10000 <= n) && (n < 100000 )){
        cout << "puluhribuan" << endl;
    }
}