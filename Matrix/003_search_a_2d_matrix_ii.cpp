// Problem: Search a 2D Matrix II
// Approach: Staircase Search
// Time Complexity: O(m+n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0, col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;      
        }
        return false;
    }
};
