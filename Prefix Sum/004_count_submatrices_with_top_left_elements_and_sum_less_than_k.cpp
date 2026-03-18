// Problem: Count Submatrices with Top-Left Element and Sum less than K(Daily Challenge -MAR 18)
// Approach: Prefix Sum
// Time Complexity: O(m * n)
// Space Complexity:O(m * n)
// Problem Link:https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/?envType=daily-question&envId=2026-03-18

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> prefix(m, vector<long long>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                prefix[i][j] = grid[i][j];
                
                if (i > 0) prefix[i][j] += prefix[i-1][j];
                if (j > 0) prefix[i][j] += prefix[i][j-1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
                
                if (prefix[i][j] <= k) count++;
            }
        }
        return count;
    }
};
