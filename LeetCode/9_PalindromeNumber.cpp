class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long res = 0, temp = x;

        while (temp != 0) {
            long long digit = temp % 10;
            res = res * 10 + digit;
            temp /= 10;
        }

        return res == x;
    }
};
