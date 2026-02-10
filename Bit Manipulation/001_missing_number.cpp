// Problem: Missing Number
// Approach: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for (int i = 0; i <= n; i++)
            xr ^= i;

        for (int x : nums)
            xr ^= x;

        return xr;
    }
};
