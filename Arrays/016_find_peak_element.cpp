// Problem: Find Peak Element
// Approach: using binary search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/3sum/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};

