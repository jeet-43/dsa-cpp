// Problem: Largest Submatrix with Rearrangements (Daily Challenge -MAR 17)
// Approach: Sorting and DP
// Time Complexity: O(m×nlogn)
// Space Complexity:O(1)
// Problem Link:https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2026-03-17

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        auto m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];

        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; j++)
                res = max(res, matrix[i][j] * (j + 1));
        }

        return res;
    }
};
