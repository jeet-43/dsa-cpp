// Problem:   Count of Smaller Numbers After Self
// Approach: Merge Sort
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Problem Link:https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int,int>> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};

        mergeSort(arr, 0, n - 1, result);
        return result;
    }

    void mergeSort(vector<pair<int,int>>& arr, int low, int high,
                   vector<int>& result) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, result);
        mergeSort(arr, mid + 1, high, result);
        merge(arr, low, mid, high, result);
    }

    void merge(vector<pair<int,int>>& arr, int low, int mid, int high,
               vector<int>& result) {
        vector<pair<int,int>> temp;
        int left = low, right = mid + 1;
        int rightCount = 0;

        while (left <= mid && right <= high) {
            if (arr[left].first <= arr[right].first) {
                result[arr[left].second] += rightCount;
                temp.push_back(arr[left++]);
            } else {
                rightCount++;
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            result[arr[left].second] += rightCount;
            temp.push_back(arr[left++]);
        }

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
};
