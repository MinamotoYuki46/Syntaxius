#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(), candies.end()); 

        vector<bool> result;
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= greatest);
        }
        
        return result;
    }
};
