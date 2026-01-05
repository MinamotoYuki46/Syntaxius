#include <bits/stdc++.h>

using namespace std; 

void solve(int n, int a, int b){
    if (a == 0 && b == 0){
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
        for(int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
        return;
    }
    
    if (a == 0 || b == 0 || a + b > n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int off = n - a - b + 1;
    for(int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';

    for(int i = 1; i < off; i++) cout << i << ' ';
    for(int i=off + a;i <= n; i++) cout << i << " ";
    for(int i=off;i < off + a; i++) cout << i << " ";
    cout << "\n";

}


int main(){
    int t; cin >> t;

    while(t--){
        int n, a, b; cin >> n >> a >> b;
        solve(n, a, b);
    }
    

    return 0;
}
