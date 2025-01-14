#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    deque<int> qu;

    scanf("%d", &testcase);
    for(int i = 0; i < testcase; i++){
        string s;
        int x, y;
        cin >> s;
        if (s == "add"){
            cin >> x >> y;
            for(int j = 0; j < x; j++){
                qu.push_back(y);
            }
            cout << qu.size() << endl;
        }
        else if (s == "del"){
            cin >> x;
            if (qu.empty()){
                cout << "0\n";
            }
            else{
                y = qu.front();
                for(int j = 0; j < x; j++){
                    qu.pop_front();
                }
            }
            cout << y << endl;
        }
        else if (s == "rev"){
            reverse(qu.begin(), qu.end());
            
        }
        
        
    }
    return 0;
}