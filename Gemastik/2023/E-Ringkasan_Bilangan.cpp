#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<pair<int, int>> hehe;
    int low, cur, seq;
    bool flag = false;
    for(auto i = mp.begin(); i != mp.end(); ++i){
        if(flag){
            if(i->first - 1 == cur){
                cur = i->first;
                seq++;
            }
            else {
                if(seq > 1){
                    hehe.push_back(make_pair(low, cur));
                }
                else hehe.push_back(make_pair(low, 0));
                flag = false;
            }
        }

        if(!flag){
            flag = true;
            low = i->first;
            cur = i->first;
            seq = 1;
            continue;
        }
    }
    if (flag) {
        if (seq > 1) {
            hehe.push_back(make_pair(low, cur));
        } else {
            hehe.push_back(make_pair(low, 0));
        }
    }

    bool flag1 = false;
    for(int i = 0; i < hehe.size(); ++i){
        if(i != hehe.size() - 1){
            flag1 = true;
        }
        if(hehe[i].second == 0) cout <<hehe[i].first;
        else cout << hehe[i].first<<"-"<<hehe[i].second;

        if(flag1){
            cout << ",";
            flag1 = false;
        }
    }
}