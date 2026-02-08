// Problem:Subarray Sums Divisible By K
// Approach: Prefix Sum
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;
        for(int x : nums){
            sum += x;
            int rem = ((sum % k) + k) % k;
            count += mp[rem];
            mp[rem]++;
        }
        return count;
    }
};
