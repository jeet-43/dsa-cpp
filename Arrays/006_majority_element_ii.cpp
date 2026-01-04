// Problem: Majority Element II
// Approach: Moore's voting algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote
              //https://leetcode.com/problems/majority-element-ii/description/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;

        for (int x : nums) {
            if (x == cand1)
                count1++;
            else if (x == cand2)
                count2++;
            else if (count1 == 0) {
                cand1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                cand2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int x : nums) {
            if (x == cand1) count1++;
            else if (x == cand2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(cand1);
        if (count2 > n / 3) result.push_back(cand2);

        return result;
    }
};

