// Problem: Shortest Subarray with Sum at least K
// Approach: Prefix Sum + Monotonic Deque
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int minLength = INT_MAX;

        for (int j = 0; j <= n; j++) {

            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                minLength = min(minLength, j - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefix[j] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
