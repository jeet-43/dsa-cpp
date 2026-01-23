// Problem: K-th missing positive number
// Approach: using binary search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Problem Link: https://leetcode.com/problems/kth-missing-positive-number/description/
             // https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/kth-missing-positive-number-in-a-sorted-array

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size() - 1;
        int ans = arr.size() + k;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing >= k) {
                ans = mid + k;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
