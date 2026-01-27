// Problem: Count distinct elements in every window
// Approach: using sliding window
// Time Complexity: O(n)
// Space Complexity: O(k)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-distinct-elements-in-every-window

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int>res;
        unordered_map<int,int>freq;
        for(int i=0;i<k;i++)freq[arr[i]]+=1;
        res.push_back(freq.size());
        for(int i=k;i<n;i++){
            freq[arr[i]]+=1;
            freq[arr[i-k]]-=1;
            if(freq[arr[i-k]]==0)freq.erase(arr[i-k]);
            res.push_back(freq.size());
        }
        return res;
    }
};
