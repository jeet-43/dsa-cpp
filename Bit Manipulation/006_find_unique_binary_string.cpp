// Problem: Find Unique Binary String (Daily Challenge -MAR 8)
// Approach: Bit Maniuplation
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0')
                result += '1';
            else
                result += '0';
        }
        return result;
    }
};
