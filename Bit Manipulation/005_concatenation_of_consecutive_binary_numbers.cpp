// Problem: Concatenation of Consecutive Binary Numbers (Daily Challenge -FEB 28)
// Approach: BitShift
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bitLength = 0;

        for (int i = 1; i <= n; i++) {
            
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }

            result = ((result << bitLength) + i) % MOD;
        }

        return result;
    }
};
