// Problem: Aggressive Cows
// Approach: using binary search
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows

class Solution {
  public:
    bool check(vector<int>&stalls,int k,int dist){
        int cnt=1;
        int prev=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-prev>=dist){
                cnt++;
                prev=stalls[i];
            }
        }
        return cnt>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int lo=1;
        int hi=stalls.back()-stalls[0];
        int res=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(stalls,k,mid)){
                res=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return res;
        
    }
};
