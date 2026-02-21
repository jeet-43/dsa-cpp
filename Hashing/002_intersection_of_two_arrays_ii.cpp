// Problem: Intersection of Two Arrays II
// Approach: HashMap
// Time Complexity: O(n+m)
// Space Complexity: O(min(n,m))
// Problem Link:https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;


        for (int num : nums1) {
            freq[num]++;
        }

        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};
