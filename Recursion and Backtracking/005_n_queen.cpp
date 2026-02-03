// Problem: N Queen
// Approach: using backtracking 
// Time Complexity: O(N!)
// Space Complexity: O(N²)
// Problem Link:https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> col, diag1, diag2;
    int n;

    void backtrack(int r) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[r - c + n - 1] || diag2[r + c])
                continue;

            board[r][c] = 'Q';
            col[c] = diag1[r - c + n - 1] = diag2[r + c] = true;

            backtrack(r + 1);

            board[r][c] = '.';
            col[c] = diag1[r - c + n - 1] = diag2[r + c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n - 1, false);
        diag2 = vector<bool>(2*n - 1, false);

        backtrack(0);
        return res;
    }
};
