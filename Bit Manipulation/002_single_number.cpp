// Problem: Single Number
// Approach: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for (int x : nums) {
            xr ^= x;
        }
        return xr;
    }
};
