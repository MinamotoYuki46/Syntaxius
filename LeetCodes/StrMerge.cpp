#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string strMerge;
        int len = min(word1.length(), word2.length());
        for(int i = 0 ; i < len; i++){
            strMerge.push_back(word1[i]);
            strMerge.push_back(word2[i]);
        }
        strMerge += word1.substr(len) + word2.substr(len);
        return strMerge;
    }
};

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    Solution sol;
    string merged = sol.mergeAlternately(word1, word2);
    cout << merged << endl;
    return 0;
}
