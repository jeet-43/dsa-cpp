// Problem: Indexes of Subarray Sum
// Approach:sliding window (using two pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int s=0,e=0;
        vector<int>res;
        int curr=0;
        for(int i=0;i<arr.size();i++){
            curr+=arr[i];
            if(curr>=target){
                e=i;
                while(curr>target&&s<e){
                    curr-=arr[s];
                    ++s;
                }
                if(curr==target){
                    res.push_back(s+1);
                    res.push_back(e+1);
                    return res;
                }
            }
        }
        return {-1};
    }
};
