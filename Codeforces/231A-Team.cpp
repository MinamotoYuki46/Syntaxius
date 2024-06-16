#include <bits/stdc++.h>
using namespace std;

struct valid{
    bool petya, vasya, tonya;
};

int main(){
    int test;
    cin >> test;
    valid problems[test];

    int solve = 0;

    for(int i = 0; i < test; i++){
        cin >> problems[i].petya >> problems[i].vasya >> problems[i].tonya;
        if (problems[i].petya && problems[i].vasya && problems[i].tonya || problems[i].petya && problems[i].vasya || problems[i].vasya && problems[i].tonya || problems[i].petya && problems[i].tonya){
            solve++;
        }
    }

    cout << solve << endl;
    return 0;
}