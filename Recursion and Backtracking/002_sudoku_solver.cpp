// Problem: Sudoku Solver
// Approach: using recursion and backtracking
// Time Complexity: O(9E)
// Space Complexity: 0(E)
// Problem Link:https://leetcode.com/problems/sudoku-solver/
             // https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621

class Solution {
public:
    bool row[9][10] = {0};
    bool col[9][10] = {0};
    bool box[9][10] = {0};

    bool solve(vector<vector<char>>& board, int cell) {
        if (cell == 81) return true;

        int r = cell / 9;
        int c = cell % 9;

        if (board[r][c] != '.')
            return solve(board, cell + 1);

        int b = (r / 3) * 3 + (c / 3);

        for (int num = 1; num <= 9; num++) {
            if (!row[r][num] && !col[c][num] && !box[b][num]) {
                board[r][c] = char(num + '0');
                row[r][num] = col[c][num] = box[b][num] = true;

                if (solve(board, cell + 1))
                    return true;

                board[r][c] = '.';
                row[r][num] = col[c][num] = box[b][num] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    int b = (i / 3) * 3 + (j / 3);
                    box[b][num] = true;
                }
            }
        }
        solve(board, 0);
    }
};
