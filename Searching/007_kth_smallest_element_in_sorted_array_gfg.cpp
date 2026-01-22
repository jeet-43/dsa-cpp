// Problem: K-th smallest element in a Sorted Array
// Approach: using binary search
// Time Complexity: O(log (max-min))
// Space Complexity: O(1)
// Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int row = n - 1, col = 0;
        int count = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countLessEqual(matrix, mid);

            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

