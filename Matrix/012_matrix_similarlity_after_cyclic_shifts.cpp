// Problem: Matrix Similarity After Cyclic Shifts (Daily Challenge -MAR 27)
// Approach: Cyclic Shfts
// Time Complexity: O(rc)
// Space Complexity:O(1)
// Problem Link:https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27

class Solution {
public:
    static bool areSimilar(vector<vector<int>>& mat, int k) {
        const int r=mat.size(),  c=mat[0].size();
        k%=c;
        if (k==0) return 1;
        for(int i=0; i<r; i++){
            bool iEven=(i&1)==0;
            for(int j=0; j<c; j++)
                if(mat[i][j]!=mat[i][(j+(iEven?c-k:k))%c]) return 0;
        }
        return 1;
    }
};
