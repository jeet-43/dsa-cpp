// Problem: Count Number of Nice Subarrays
// Approach: Prefix Sum + Hash Maps
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;

        for(int x : nums){
            sum += x % 2;
            if(mp.count(sum - k))
                count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};

