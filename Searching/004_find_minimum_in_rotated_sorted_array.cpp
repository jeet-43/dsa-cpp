// Problem: Find minimum in Rotated Sorted Array
// Approach: using binary search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611
             // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            if (nums[lo] < nums[hi])
                return nums[lo];

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        return nums[lo];
    }
};

