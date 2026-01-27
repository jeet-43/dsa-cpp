// Problem: Maximim Sum of Distinct Subarray
// Approach: using sliding window
// Time Complexity: O(n)
// Space Complexity: O(k)
// Problem Link:https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0, ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            freq[nums[i]]++;

            if (i >= k) {
                sum -= nums[i - k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0)
                    freq.erase(nums[i - k]);
            }

            if (freq.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
