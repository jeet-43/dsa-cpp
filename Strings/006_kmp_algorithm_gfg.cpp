// Problem: search pattern(kmp algorithm)
// Approach: kmp algo
// Time Complexity: O(n+m)
// Space Complexity: O(m)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int n=txt.size(),m=pat.size();
        vector<int>lps(m,0),ans;
        for(int i=1,len=0;i<m;){
            if(pat[i]==pat[len]){
                lps[i++]=++len;
            }
            else if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i++]=0;
            }
        }
        for(int i=0,j=0;i<n;){
            if(txt[i]==pat[j]){
                i++;j++;
            }
            if(j==m){
                ans.push_back(i-j);
                j=lps[j-1];
            }
            else if(i<n&&txt[i]!=pat[j]){
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return ans;
    }
};
