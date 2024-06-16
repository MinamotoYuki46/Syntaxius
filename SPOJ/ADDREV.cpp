#include <bits/stdc++.h>
using namespace std;

struct numrev{
    int num1, num2;
};

int reverse(int x){ 
    int temp = x;
    int ret = 0;

    while (temp>0){
        ret = (ret* 10) + (temp % 10);
        temp /= 10;
    }
    return ret;
}

int main(){
    int testcase;
    cin >> testcase;
    numrev num[testcase];

    for(int i = 0 ; i < testcase ; i++){
        cin >> num[i].num1 >> num[i].num2;
        int result = reverse(num[i].num1) + reverse(num[i].num2);
        cout << reverse(result) << endl;
    }
    ;

    return 0;
}