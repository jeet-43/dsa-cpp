// Problem: Complement of Base 10 Integer (Daily Challenge - 11 March)
// Approach: Bit Maniuplation
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;

        int mask = 0;
        int temp = n;

        while(temp){
            mask = (mask<<1) | 1;
            temp >>= 1;
        }
        return mask ^ n;
    }
};
