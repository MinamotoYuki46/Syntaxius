#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcase, numAccounts;

    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        cin >> numAccounts;
        cin.ignore();

        vector<string> accounts;

        for (int j = 0; j < numAccounts; j++) {
            string accountName;
            getline(cin, accountName);
            accounts.push_back(accountName);
            
        }

        sort(accounts.begin(), accounts.end());

        map<string, int> accountsCount;

        for(const auto& str : accounts) {
            accountsCount[str]++;
        }

        for (const auto& k : accountsCount) {
            cout << k.first << k.second << endl;
        }
        cout << endl;
    }

    return 0;
}