#include<bits/stdc++.h>
#define int long long
using namespace std;

void c_p_c(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void bubble_sort(vector<int> &arr){
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}



int32_t main(){
    // c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        vector<int> a;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int in;
            cin >> in;
            a.push_back(in);
        }
        int count = 0;
        // this will be the qualification to make the code fashionable
        bubble_sort(a);
        if((a[0] + a[a.size()-1]) % 2 == 0){
            cout << count << '\n';
        }else{
            for(int i = 1; i < a.size(); i++){
                if((a[i] + a[a.size()-1]) % 2 ==0){
                    count = i;
                    break;
                }
            }
            for(int i = a.size()-1; i > 0; i--){
                if((a[i-1] + a[0]) % 2 ==0){
                    if((a.size() -1) - i < count){
                        count = a.size() - i;
                        break;
                    }
                }
            }
            if(count > 0){
                cout << count << '\n';
            }else cout << "count > 0\n";
            
        }
    }

    return 0;
}