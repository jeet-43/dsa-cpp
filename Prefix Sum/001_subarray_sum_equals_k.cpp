// Problem: Subarray Sum Equals K
// Approach: Prefix Sum + Hashing
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/subarray-sum-equals-k/submissions/1912387474/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;

        for(int x : nums){
            sum += x;
            if(mp.count(sum - k))
                count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};
