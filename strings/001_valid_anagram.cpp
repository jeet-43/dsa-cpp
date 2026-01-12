// Problem: valid anagram
// Approach: using frequesncy array
// Time Complexity: O(n+m)
// Space Complexity: O(1)
// Problem Link:https:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620
              // https://leetcode.com/problems/valid-anagram/description/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        for (char ch : t)
            freq[ch - 'a']--;

        for (int count : freq) {
            if (count != 0)
                return false;
        }

        return true;
    }
};
