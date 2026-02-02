// Problem: Permuntations II
// Approach: using backtracking and frequency map
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/permutations-ii/description/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr,
                   unordered_map<int,int>& cnt,
                   vector<vector<int>>& res, int n) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for (auto &p : cnt) {
            if (p.second == 0) continue;

            curr.push_back(p.first);
            p.second--;
            backtrack(nums, curr, cnt, res, n);
            curr.pop_back();
            p.second++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;

        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, curr, cnt, res, nums.size());
        return res;
    }
};
