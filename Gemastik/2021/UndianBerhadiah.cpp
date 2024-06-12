#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int div (int n){
    int temp = n;
    int size = 0;
    while (temp > 0){
        size++;
        temp/=10;
    }
    return size;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<int> arr;
    vector<int> arr2;
    for(int i = 0; i < a; ++i){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int mins = INT_MAX;
    for(int i = 0; i < a; ++i){
        mins = min(abs(b - arr[i]), mins);
    }

    for(auto x : arr){
        if((x == b - mins)||(x == b + mins)){
            arr2.push_back(x);
        }
    }
    sort(arr2.begin(), arr2.end());
    for(auto x : arr2){
        int size = div (x);
        for(int i = 0; i < 5 - size; ++i){
            cout << '0';
        }
        cout << x<<endl;
    }
    return 0;
}