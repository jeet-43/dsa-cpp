// Problem: Subarray Product Less Than K
// Approach: Sliding Window (using two pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0;
        long long prod = 1;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};
