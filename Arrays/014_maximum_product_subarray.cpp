// Problem: maximum product subarray
// Approach: Kadane's Algorithm (by traversing in both directions)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/maximum-product-subarray3604
              // https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            if (curr < 0) {
                int temp = maxEnd;
                maxEnd = minEnd;
                minEnd = temp;
            }

            if (curr > maxEnd * curr)
                maxEnd = curr;
            else
                maxEnd = maxEnd * curr;

            if (curr < minEnd * curr)
                minEnd = curr;
            else
                minEnd = minEnd * curr;

            if (maxEnd > ans)
                ans = maxEnd;
        }

        return ans;
    }
};
