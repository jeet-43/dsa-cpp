// Problem: Trapping Rain Water
// Approach: using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621
             // https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 1, right = n - 2;
        int lMax = height[0];
        int rMax = height[n - 1];
        int res = 0;

        while (left <= right) {
            if (lMax <= rMax) {
                res += max(0, lMax - height[left]);
                lMax = max(lMax, height[left]);
                left++;
            } else {
                res += max(0, rMax - height[right]);
                rMax = max(rMax, height[right]);
                right--;
            }
        }
        return res;
    }
};
