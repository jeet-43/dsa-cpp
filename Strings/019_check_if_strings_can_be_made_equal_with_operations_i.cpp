// Problem: Check if Strings Can be Made Equal With Operations I (Daily Challenge - Mar 29)
// Approach: Comparing
// Time Complexity: O(1)
// Space Complexity: O(1)
// Problem Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool s02=s1[0]==s2[2] && s1[2]==s2[0];
        bool b02=s1[0]==s2[0] && s1[2]==s2[2];
        bool s13=s1[1]==s2[3] && s1[3]==s2[1];
        bool b13=s1[1]==s2[1] && s1[3]==s2[3];
        return ((s02 ||b02)&&(s13 || b13));
    }
};
