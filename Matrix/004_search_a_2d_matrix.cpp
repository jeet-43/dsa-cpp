// Problem: Search a 2D Matrix 
// Approach: Binary Search
// Time Complexity: O(log(mxn))
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / cols;
            int c = mid % cols;

            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

