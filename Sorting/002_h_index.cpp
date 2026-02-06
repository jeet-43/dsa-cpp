// Problem: H-Index
// Approach: Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/h-index/description/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                h = max(h, n - i);
            }
        }
        return h;
    }
};
