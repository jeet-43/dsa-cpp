// Problem: Count Pairs whose Sum is less than given target
// Approach: using two pointers
// Time Complexity: O(n*logn+n) 
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int left=0,right=arr.size()-1;
        int cnt=0;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum<target){
                cnt+=(right-left);
                left++;
            }else{
                right--;
            }
        }
        return cnt;
        
    }
};

