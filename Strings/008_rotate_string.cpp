// Problem: rotate string
// Approach: KMP algo
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620
            //  https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    vector<int> computeLPS(string &pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        int len = 0;

        for (int i = 1; i < n; ) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }

    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s.empty()) return true;

        string txt = s + s;
        vector<int> lps = computeLPS(goal);

        int i = 0, j = 0;
        while (i < txt.size()) {
            if (txt[i] == goal[j]) {
                i++;
                j++;
            }

            if (j == goal.size()) {
                return true;
            } 
            else if (i < txt.size() && txt[i] != goal[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }
};

