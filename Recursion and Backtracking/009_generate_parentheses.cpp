// Problem: Generate Parentheses
// Approach: Backtracking
// Time Complexity: ≈ O(4^n / √n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> res;

    void backtrack(string curr, int open, int close, int n) {
        if(curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if(open < n)
            backtrack(curr + "(", open + 1, close, n);

        if(close < open)
            backtrack(curr + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }
};
