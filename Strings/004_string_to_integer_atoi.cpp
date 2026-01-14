// Problem: string to integer atoi
// Approach: greedy string parsing
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/string-to-integer-atoi/description/
             // https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, idx = 0;
        long long res = 0;
        while (idx < s.length() && s[idx] == ' ') {
            idx++;
        }
        if (idx < s.length() && (s[idx] == '-' || s[idx] == '+')) {
            if (s[idx] == '-') {
                sign = -1;
            }
            idx++;
        }
        while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
            res = res * 10 + (s[idx] - '0');
            if (res > INT_MAX) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            idx++;
        }
        return (int)(res * sign);
    }
};
