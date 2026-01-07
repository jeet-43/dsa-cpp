// Problem: Minimize the Heights II
// Approach: using Quick sort
// Time Complexity: O(n log n)
// Space Complexity: O(log n)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351

class Solution {
  public:
    void quickSort(vector<int>&arr,int low,int high){
        if(low>=high)return;
        int pivot =arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(arr [j]<=pivot){
                i++;
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        int temp=arr[i+1]; 
        arr[i+1]=arr[high];
        arr[high]=temp;
        
        int pi=i+1;
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        if(n==1)return 0;
        quickSort(arr,0,n-1);
        int res=arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-k<0)continue;
            int minH;
            if(arr[0]+k<arr[i]-k)minH=arr[0]+k;
            else minH=arr[i]-k;
            int maxH;
            if (arr[i-1]+k>arr[n-1]-k)
            maxH=arr[i-1]+k;
            else
            maxH=arr[n-1]-k;
            if(maxH-minH<res)
            res=maxH-minH;
        }
        return res;
        
    }
};
