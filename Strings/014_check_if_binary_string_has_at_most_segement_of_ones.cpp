// Problem: Check if Binary String Has at Most One Segement of Ones (Daily Challenge -MAR 6)
// Approach: Scan
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/?envType=daily-question&envId=2026-03-06

class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                count++;
            }
        }

        return count <= 1;
    }
};
