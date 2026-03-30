// Problem: Check if Strings Can be Made Equal with Operations II
// Approach: Sorting 
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/submissions/1963953769/?envType=daily-question&envId=2026-03-30

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        array<string, 2> A, B;
        for (int i = 0; i < s1.length(); i++) {
            int off = i & 1;
            A[off] += s1[i];
            B[off] += s2[i];
        }

        for (int i = 0; i < 2; i++) {
            sort(A[i].begin(), A[i].end());
            sort(B[i].begin(), B[i].end());
        }

        return A == B;
    }
};
