#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> temp(n);
    int sum = 0;
    for(int i= 0; i < n; ++i){
        cin >> arr[i];
        temp[i] = arr[i];
        sum += arr[i];
    }

    int avg = sum / n;

    sort(temp.rbegin(), temp.rend());
    int beda = 0;
    for(int i = 0; i < n; ++i){
        if(beda > 2) break;
        if(arr[i] != avg) beda++; 
    }

    if(beda == 0){
        cout <<"SESUAI";
        return 0;
    }
    else if(beda == 1 || beda > 2){
        cout <<"TIDAK SESUAI";
        return 0;
    }
    
    int maks;
    int mins;
    for(int i = 0; i < n; ++i){
        if(arr[i] == temp[0]){
            maks = i +1;
            break;
        }
    }

    for(int i = 0; i < n; ++i){
        if(arr[i] == temp[n - 1]){
            mins = i + 1;
            break;
        }
    }

    if(temp[0] - avg == abs(temp[n - 1] - avg)) cout << temp[0] - avg<<" "<<maks<<" "<<mins;
    else cout <<"TIDAK SESUAI";

}