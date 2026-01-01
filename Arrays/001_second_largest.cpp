// Problem: Second Largest Element in an Array
// Approach: Single traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/second-largest3735


int getSecondLargest(int *arr, int n) {
    // code here
    int largest =-1,secondLargest=-1;
    for (int i=0;i<n;i++){
        if (arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;
}
    
