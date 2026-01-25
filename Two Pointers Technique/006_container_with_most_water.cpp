// Problem: Container With Most Water
// Approach: using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/container-with-most-water0535
             // https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;

        while (left < right) {
            int water = min(height[left], height[right]) * (right - left);
            res = max(res, water);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return res;
    }
};

