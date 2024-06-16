#include<bits/stdc++.h>
using namespace std;

int main(){
    string que;
    int n, t;

    cin >> n >> t >> que;

    while(t--){
        vector<int> key;
        for(int i = 0; i < n - 1;i++){
            if(que[i] == 'B' && que[i+1] == 'G'){
                key.push_back(i);
            }
        }
        for(auto index:key){
            swap(que[index], que[index+1]);
        }
    }

    cout << que;

    return 0;
}