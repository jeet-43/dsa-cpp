// Problem: Stock Buy and Sell - Max one Transaction (geeks for geeks)
         // Best Time to Buy and Sell Stock (leetcode)
// Approach: One Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2
             // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar=prices[0],res=0;
        for(int i=1;i<prices.size();i++){
            minSoFar=min(minSoFar,prices[i]);
            res=max(res,prices[i]-minSoFar);
        }
        return res;
        
    }
};
