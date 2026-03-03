// Problem: Find Kth Bit in Nth Binary String  (Daily Challenge -MAR 3)
// Approach: Recursion
// Time Complexity:O(n)
// Space Complexity:O(n)
// Problem Link:https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2026-03-03

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int len = 1 << n;  

        if (k < len / 2) {
            return findKthBit(n - 1, k);
        }
        else if (k == len / 2) {
            return '1';
        }
        else {
            char correspondingBit = findKthBit(n - 1, len - k);
            return (correspondingBit == '0') ? '1' : '0';
        }
    }
};
