#include <bits/stdc++.h>
#include <climits>
using namespace std;

int factorial(int num) {
    if (num == 1 || num == 0){
        return 1;
    }
    return num * factorial(num - 1);
}

int main() {
    int testcase;
    cin >> testcase;

    vector<int> numbers(testcase);

    for (int i = 0; i < testcase; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < testcase; i++) {
        long long int fact = 0;
        fact = factorial(numbers[i]);
        cout << fact << endl;
    }

    return 0;
}
