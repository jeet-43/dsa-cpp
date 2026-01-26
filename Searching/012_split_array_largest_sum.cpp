  // Problem: Splir Array Largest Sum
// Approach: using binary search
// Time Complexity: O(n log(sum(nums)))
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    bool check(vector<int>& nums, int k, int limit) {
        int cnt = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > limit) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int lo = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > lo)
                lo = nums[i];
        }

        int hi = 0;
        for (int i = 0; i < n; i++)
            hi += nums[i];

        int res = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(nums, k, mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }
};
