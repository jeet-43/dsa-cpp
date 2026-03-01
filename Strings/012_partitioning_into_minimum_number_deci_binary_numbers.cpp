// Problem: Partitioning Into Minimum Number of Deci-Binary Numbers (Daily Challenge -MAR 1)
// Approach: Max Digit
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        
        for (char c : n) {
            maxDigit = max(maxDigit, c - '0');
        }
        
        return maxDigit;
    }
};
