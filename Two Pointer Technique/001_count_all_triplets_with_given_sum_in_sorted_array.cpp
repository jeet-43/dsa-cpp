// Problem: Count all the triplets with given sum in sorted arrat
// Approach: Two Pointers Techinique
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-all-triplets-with-given-sum-in-sorted-array

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n=arr.size();
        int res=0;
        for(int i=0;i<n-2;i++){
            int left=i+1,right=n-1;
            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    int ele1=arr[left],ele2=arr[right];
                    int cnt1=0,cnt2=0;
                    while(left<=right&&arr[left]==ele1){
                        cnt1++;
                        left++;
                    }
                    while(left<=right&&arr[right]==ele2){
                        cnt2++;
                        right--;
                    }
                    if(ele1==ele2) res+=(cnt1*(cnt1-1))/2;
                    else res+=(cnt1*cnt2);
                }
            }
        }
        return res;
    }
};
