// Problem: Next Permuntation
// Approach: next permuntation
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226
                      //https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
      
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            int l = 0, r = n - 1;
            while (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            return;
        }

        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        int left = pivot + 1;
        int right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
