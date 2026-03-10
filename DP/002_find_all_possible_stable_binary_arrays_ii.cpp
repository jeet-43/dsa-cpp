// Problem: Find All Possible Stable Binary Arrays II (Daily Challenge -MAR 10)
// Approach: DP
// Time Complexity: O(zero × one )
// Space Complexity: O(zero × one)
// Problem Link:https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/?envType=daily-question&envId=2026-03-10

class Solution {
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(
            zeros + 1,
            vector<vector<int>>(ones + 1, vector<int>(2, 0))
        );

        for (int z = 0; z <= min(zeros, limit); z++)
            dp[z][0][0] = 1;

        for (int o = 0; o <= min(ones, limit); o++)
            dp[0][o][1] = 1;

        for (int z = 1; z <= zeros; z++) {
            for (int o = 1; o <= ones; o++) {

                long long addZero = (long long)dp[z-1][o][0] + dp[z-1][o][1];
                if (z - 1 - limit >= 0)
                    addZero -= dp[z - 1 - limit][o][1];

                dp[z][o][0] = (addZero % MOD + MOD) % MOD;


                long long addOne = (long long)dp[z][o-1][0] + dp[z][o-1][1];
                if (o - 1 - limit >= 0)
                    addOne -= dp[z][o - 1 - limit][0];

                dp[z][o][1] = (addOne % MOD + MOD) % MOD;
            }
        }

        return (dp[zeros][ones][0] + dp[zeros][ones][1]) % MOD;
    }
};
