// Problem: Search in Rotated Array
// Approach: using binary search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Problem Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618
             // https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[lo]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};
