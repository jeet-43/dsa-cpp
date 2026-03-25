// Problem: Equal Sum Grid Partition I(Daily Challenge -MAR 25)
// Approach: Prefix Sum
// Time Complexity: O(m × n)
// Space Complexity:O(m + n)
// Problem Link:https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        vector<long long> row(m, 0), col(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        if (total % 2 != 0) return false;
        long long target = total / 2;

        long long sum = 0;
        for (int i = 0; i < m - 1; i++) {
            sum += row[i];
            if (sum == target) return true;
        }

        sum = 0;
        for (int j = 0; j < n - 1; j++) {
            sum += col[j];
            if (sum == target) return true;
        }

        return false;
    }
};
