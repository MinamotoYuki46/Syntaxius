#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    deque<int> st;
    int x, y, z = 0;
    scanf("%d", &testcase);
    for(int i = 0; i < testcase; i++){
        string s;
        
        cin >> s;
        if (s == "add"){
            cin >> x >> y;
            st.insert(st.end(), y, x-z);
            cout << st.size() << endl;
        }
        else if (s == "del"){
            if (st.empty()){
                cout << "0\n";
            }
            else{
                cin >> x;
                cout << st.back() + z << endl;
                st.resize(st.size() - x);
            }
        }
        else if(s == "adx"){
            cin >> x;
            z += x;
        }
        else if(s == "dex"){
            cin >> x;
            z -= x;
        }
        else if (s == "rev"){
            reverse(st.begin(), st.end());
            
        }
        
    }
    return 0;
}