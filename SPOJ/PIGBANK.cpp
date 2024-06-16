#include <bits/stdc++.h>
using namespace std;

struct coins {
    int currency, weight;
};

struct pigBank {
    int empty, filled, numCoins;
    int range;
    coins coin[501];

    pigBank(int e, int f, int n) : empty(e), filled(f), numCoins(n), range(f - e) {
        for (int i = 0; i < numCoins; i++) {
            cin >> coin[i].currency >> coin[i].weight;
        }
    }
};

int main() {
    int testcase, dp[10000];
    cin >> testcase;

    while (testcase--) {
        int empty, filled, numCoins;
        vector<int> result = {};
        cin >> empty >> filled >> numCoins;

        pigBank PB(empty, filled, numCoins);

        dp[0] = 0;

        for(int i = 1; i <= PB.range;i++){
            dp[i] = -1;
            for(int j = 0; j < PB.numCoins; j++){
                if(i >= PB.coin[j].weight && dp[i - PB.coin[j].weight] != -1 && (dp[i] == -1 || PB.coin[j].currency + dp[i - PB.coin[j].weight] <= dp[i])){
                    dp[i] = PB.coin[j].currency + dp[i - PB.coin[j].weight];
                }
            }
        }

        if (dp[PB.range] == -1) {
            cout << "This is impossible." << endl;
        } 
        else {
            cout << "The minimum amount of money in the piggy-bank is " << dp[PB.range] << "." << endl;
        }
    }

    return 0;
}
