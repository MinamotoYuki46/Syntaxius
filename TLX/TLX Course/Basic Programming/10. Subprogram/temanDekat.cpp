#include <bits/stdc++.h>

using namespace std;

int fx(int xi, int xj, int yi, int yj, int d){
    return pow(abs(xj - xi), d) + pow(abs(yj - yi), d);
}

int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    int x[n], y[n];

    for (int i = 0; i < n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < n;i++){
        for(int j = i+1; j < n; j++){
            int result = fx(x[i], x[j], y[i], y[j], d);

            if (result < min){
                min = result;
            }
            if (result > max){
                max = result;
            }

        }
    }
    printf("%d %d", min, max);
    return 0;
    }