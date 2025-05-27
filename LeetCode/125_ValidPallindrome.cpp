// LeetCode Problem: Valid Pallindrome
// Problem URL: https://leetcode.com/problems/valid-palindrome
// Difficulty: Easy 
// Solution Date: 20 November 2024

// Problem Statement:
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
// it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Constraint
// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

// Approach:
// compare the element l and r. if difference, return false. set the char into lowercase. If we found non-alphanumeric, skip it by raise the l or lower the r

// Complexity Analysis:
// Time Complexity: O(n) - traverse til n/2 
// Space Complexity: O(1) - stroing pointer and size

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;

        while (l < r){
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else if (tolower(s[l]) != tolower(s[r])) return false;
            else {
                l++; r--;
            }
        }

        return true;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Example test case
    string str = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(str);
    cout << "Result: " << result << endl;
    return 0;
}