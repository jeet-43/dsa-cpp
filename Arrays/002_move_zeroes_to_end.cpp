// Problem: Move Zeroes 
// Approach: One traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/move-all-zeroes-to-end-of-array0751
// :https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=0){
                swap(nums[i],nums[count]);
                count++;
            }
        }
        
    }
};
