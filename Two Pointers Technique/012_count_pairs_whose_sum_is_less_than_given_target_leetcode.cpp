// Problem: Count Pairs whose Sum is less than Given Target
// Approach: using two pointers
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        int cnt = 0;

        while (left < right) {
            if (nums[left] + nums[right] < target) {
                cnt += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return cnt;
    }
};

