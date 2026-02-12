// Problem: Single Number II
// Approach: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/single-number-ii/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;
            for (int num : nums) {
                if ((num >> bit) & 1) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                ans |= (1 << bit);
            }
        }
        return ans;
    }
};

