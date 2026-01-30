// Problem: Pow(x,n)
// Approach: using recursion
// Time Complexity: O(log |e|)
// Space Complexity: O(log |e|)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/powx-n
             // https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;          
        return fastPow(x, N);
    }

    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;

        if (n < 0) return 1.0 / fastPow(x, -n);

        double half = fastPow(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};


