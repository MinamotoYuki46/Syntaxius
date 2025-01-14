#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(long long x, long long y){
    if (y == 0){
        return x;
    }
    else {
        return gcd(y, x%y);
    }
}

/*
lcm(a,b) = a * b / gcd(a, b)
lcm(a, b, c) = lcm(lcm(a, b), c)
*/
int main(){
    int testcase, nums[20];
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++){
        scanf("%d", &nums[i]);
    }
    ll lcm = nums[0];

    for (int i = 1; i < testcase; i++){
        lcm = nums[i] * lcm / gcd(nums[i], lcm);
    }
    printf("%d", lcm);
    return 0;
}