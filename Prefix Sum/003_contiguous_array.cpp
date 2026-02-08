// Problem: Contiguous Array
// Approach: Prefix Sum + Hashing
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;

        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] == 0 ? -1 : 1);
            if(mp.count(sum))
                ans = max(ans, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return ans;
    }
};

