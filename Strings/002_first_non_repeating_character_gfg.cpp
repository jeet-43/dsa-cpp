// Problem: first non repeating character
// Approach: by storing indices (one traversal)
// Time Complexity: O(n)
// Space Complexity: O(MAX_CHAR)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/non-repeating-character-1587115620

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        const int MAX_CHAR = 26;
        vector<int> vis(MAX_CHAR, -1);

        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (vis[index] == -1) {
                vis[index] = i;
            } else {
                vis[index] = -2;
            }
        }

        int idx = -1;
        for (int i = 0; i < MAX_CHAR; i++) {
            if (vis[i] >= 0) {
                if (idx == -1 || vis[i] < vis[idx]) {
                    idx = i;
                }
            }
        }

        if (idx == -1)
            return '$';

        return s[vis[idx]];
    }
};
