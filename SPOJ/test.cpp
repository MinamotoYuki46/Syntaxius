#include <bits/stdc++.h>
using namespace std;

struct coins {
    int currency, weight;
};

int unboundedKnapsack(int empty, int filled, vector<coins>& coin) {
    vector<int> dp(filled - empty + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= filled - empty; i++) {
        for (int j = 0; j < coin.size(); j++) {
            if (coin[j].weight <= i) {
                int withoutCoin = dp[i];
                int withCoin = dp[i - coin[j].weight] + coin[j].currency;
                dp[i] = min(withoutCoin, withCoin);
            }
        }
    }

    return (dp[filled - empty] == INT_MAX) ? -1 : dp[filled - empty];
}

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int empty, filled, numCoins;
        cin >> empty >> filled >> numCoins;

        vector<coins> coin(numCoins);

        for (int i = 0; i < numCoins; i++) {
            cin >> coin[i].currency >> coin[i].weight;
        }

        int result = unboundedKnapsack(empty, filled, coin);

        if (result != -1) {
            cout << "The minimum amount of money in the piggy-bank is " << result << "." << endl;
        } else {
            cout << "This is impossible." << endl;
        }
    }

    return 0;
}