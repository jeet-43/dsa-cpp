// Problem: Allocate Minimum Pages
// Approach: using binary search
// Time Complexity: O(n log(sum(nums)))
// Space Complexity: O(1)
// Problem Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/allocate-minimum-number-of-pages0937

class Solution {
  public:
    bool check(vector<int>&arr,int k,int pageLimit){
        int cnt=1;
        int pageSum=0;
        for(int i=0;i<arr.size();i++){
            if(pageSum+arr[i]>pageLimit){
                cnt++;
                pageSum=arr[i];
            }
            else{
                pageSum+=arr[i];
            }
        }
        return cnt<=k;
    }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n)return -1;
        int lo=arr[0];
        for (int i=1;i<n;i++){
            if(arr[i]>lo)lo=arr[i];
        }
        int hi=0;
        for(int i=0;i<n;i++){
            hi+=arr[i];
        }
        int res=1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(arr,k,mid)){
                res=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return res;
    }
};
