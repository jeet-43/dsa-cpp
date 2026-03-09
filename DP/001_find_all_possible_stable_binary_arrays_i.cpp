// Problem: Find All Possible Stable Binary Arrays I (Daily Challenge -MAR 10)
// Approach: DP
// Time Complexity: O(zero × one × limit)
// Space Complexity: O(zero × one)
// Problem Link:https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp0(zero+1, vector<long long>(one+1));
        vector<vector<long long>> dp1(zero+1, vector<long long>(one+1));

        dp0[0][0] = dp1[0][0] = 1;

        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){

                for(int k=1;k<=limit && k<=i;k++){
                    dp0[i][j] = (dp0[i][j] + dp1[i-k][j]) % MOD;
                }

                for(int k=1;k<=limit && k<=j;k++){
                    dp1[i][j] = (dp1[i][j] + dp0[i][j-k]) % MOD;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};
