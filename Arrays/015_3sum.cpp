// Problem: 3sum
// Approach: Sorting + Two Pointers
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return ans;
    }
};
