#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> point;
    int sum = 0;
    int input;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        point.push_back(input);
    }
    sort(point.begin(), point.end());
    int range = point[2] - point[0];
    
    cout << range;

    return 0;
}
