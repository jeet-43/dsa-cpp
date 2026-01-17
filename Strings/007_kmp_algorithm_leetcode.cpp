// Problem: find the index of the first occurence in the string
// Approach: KMP algo
// Time Complexity: O(n+m)
// Space Complexity: O(m)
// Problem Link:https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        for (int i = 0, j = 0; i < n; ) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            }

            if (j == m) {
                return i - j;
            }
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};

            
