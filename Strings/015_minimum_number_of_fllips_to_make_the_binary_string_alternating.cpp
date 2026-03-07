// Problem: Minimum Nuber of Flips to Make the Binary String Alternating (Daily Challenge -MAR 7)
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/?envType=daily-question&envId=2026-03-07

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;
        string alt1 = "", alt2 = "";

        for (int i = 0; i < 2*n; i++) {
            alt1 += (i % 2 ? '1' : '0');
            alt2 += (i % 2 ? '0' : '1');
        }
        int res = INT_MAX;
        int diff1 = 0, diff2 = 0;
        int left = 0;

        for (int right = 0; right < 2*n; right++) {

            if (s2[right] != alt1[right]) diff1++;
            if (s2[right] != alt2[right]) diff2++;

            if (right - left + 1 > n) {
                if (s2[left] != alt1[left]) diff1--;
                if (s2[left] != alt2[left]) diff2--;
                left++;
            }

            if (right - left + 1 == n)
                res = min(res, min(diff1, diff2));
        }
        return res;
    }
};
