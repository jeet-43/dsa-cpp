// Problem: Sum pair closest to target
// Approach: using two pointers
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-in-array-whose-sum-is-closest-to-x1124

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int left=0,right=arr.size()-1;
        int minDiff=INT_MAX;
        vector<int> res;
        while(left<right){
            int currSum=arr[left]+arr[right];
            int diff=abs(target-currSum);
            if(diff<minDiff){
                minDiff=diff;
                res={arr[left],arr[right]};
            }
            
            if(currSum<target)left++;
            else right--;
        }
        return res;
    }
};
