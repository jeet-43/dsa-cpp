// Problem: Reverse Integer
// Approach: Digit Manipulation
// Time Complexity: O(log10(x))
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;

            if (rev > INT_MAX || rev < INT_MIN)
                return 0;

            x /= 10;
        }

        return rev;
    }
};
