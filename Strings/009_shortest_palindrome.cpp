// Problem: rotate string
// Approach: KMP algo
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome
            //  https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
public:
    vector<int> computeLPSArray(string &pat) {
        int n = pat.length();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return s;

        string rev = "";
        for (int i = n - 1; i >= 0; i--) {
            rev += s[i];
        }

        string temp = s + "$" + rev;
        vector<int> lps = computeLPSArray(temp);

        int charsToAdd = n - lps.back();

        return rev.substr(0, charsToAdd) + s;
    }
};
