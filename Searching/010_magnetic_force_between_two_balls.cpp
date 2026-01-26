// Problem: Magnetic Force Between Two Balls
// Approach: using binary search
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link: https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {
public:
    bool canPlace(vector<int>& pos, int m, int dist) {
        int cnt = 1;
        int prev = pos[0];

        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - prev >= dist) {
                cnt++;
                prev = pos[i];
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int lo = 1;
        int hi = position.back() - position[0];
        int ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(position, m, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
