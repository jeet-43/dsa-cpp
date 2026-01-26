// Problem: Longest Substring Without Repeating Character
// Approach: using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848
             // https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            if (last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }
            last[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
