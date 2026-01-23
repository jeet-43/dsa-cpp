// Problem: 3Sum with Multiplicity
// Approach: two pointers
// Time Complexity: O(n²)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/3sum-with-multiplicity/description/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long res = 0;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            int need = target - arr[i];

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum < need) {
                    left++;
                }
                else if (sum > need) {
                    right--;
                }
                else {
                    if (arr[left] == arr[right]) {
                        long long cnt = right - left + 1;
                        res += (cnt * (cnt - 1)) / 2;
                        res %= MOD;
                        break;
                    }
                    long long cnt1 = 1, cnt2 = 1;
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        cnt1++;
                        left++;
                    }
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        cnt2++;
                        right--;
                    }

                    res += cnt1 * cnt2;
                    res %= MOD;

                    left++;
                    right--;
                }
            }
        }
        return res % MOD;
    }
};
