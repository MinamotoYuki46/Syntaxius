#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

void solve(){
    Point p[4];
    for (int i = 0; i < 4; i++){
        cin >> p[i].x >> p[i].y;
    }

    if ( (min(p[1].x, p[2].x)< p[3].x && max(p[1].x, p[2].x) > p[3].x && min(p[1].y, p[2].y)<=p[3].y && max(p[1].y, p[2].y) >= p[3].y ) ^ 
    (min(p[1].x, p[2].x)<p[4].x && max(p[1].x, p[2].x) > p[4].x && min(p[1].y, p[2].y)<=p[4].y && max(p[1].y, p[2].y) >=p[4].y )){
        cout << "TIDAK" << endl;
    }
    else{
        cout << "YA" << endl;
    }
    
}


int main(){
    int testcase;
    cin >> testcase;
    while (testcase--){
        solve();
    }
    return 0;
}