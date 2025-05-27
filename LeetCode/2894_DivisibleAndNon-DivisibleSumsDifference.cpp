// LeetCode Problem: Problem Title
// Problem URL: URL
// Difficulty: Difficulty
// Solution Date: Date

// Problem Statement:
// Brief problem description.

// Constraint
// Brief problem description.

// Approach:
// Explain approach here.

// Complexity Analysis:
// Time Complexity: O(...) - Explain
// Space Complexity: O(...) - Explain

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int div = floor(n / m);
        int sumDiv = div * (div + 1) / 2 * m;

        int sumAll = n * (n + 1) / 2;

        return sumAll - 2 * sumDiv;
    }
};

// Optional: Main function for quick testing
// int main() {
//     Solution sol;
//     // Example test case
//     <ReturnType> result = sol.functionName(test parameters);
//     cout << "Result: " << result << endl;
//     return 0;
// }