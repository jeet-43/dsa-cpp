// Problem: Number of occurence
// Approach: using binary search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/number-of-occurrence2259

class Solution {
  public:
    int firstOccurence(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int>&arr,int target){
        int low=0,high=arr.size()-1;
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>&arr,int target){
        int first=firstOccurence(arr,target);
        if(first==-1)return 0;
        
        int last=lastOccurence(arr,target);
        return last-first+1;
    }
    
};

