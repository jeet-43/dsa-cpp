// Problem: Palindrome Number
// Approach: Intger Maniuplation
// Time Complexity: O(log10(n))
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long long rev = 0;
        int original = x;
        while(x > 0){
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev == original;
    }
};
