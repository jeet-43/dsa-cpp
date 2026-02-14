// Problem: Rotate Image
// Approach: Transpose + Reverse Rows
// Time Complexity:O(n²)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
