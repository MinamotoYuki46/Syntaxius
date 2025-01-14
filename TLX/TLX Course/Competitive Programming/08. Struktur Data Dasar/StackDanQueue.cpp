#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> list;
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        string s;
        int x;
        cin >> s;
        if (s == "push_back"){
            cin >> x;
            list.push_back(x);
        }
        else if (s == "push_front"){
            cin >> x;
            list.push_front(x);
        }
        else if (s == "pop_back"){
            list.pop_back();
        }
        else if (s == "pop_front"){
            list.pop_front();
        }
    }

    for (auto j : list){
        cout << j << endl;
    }

    return 0;
}