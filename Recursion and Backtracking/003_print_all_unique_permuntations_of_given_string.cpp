// Problem: Print all Unique Permuntations of a given string
// Approach: using backtracking and frequency map
// Time Complexity: O(n)
// Space Complexity: O(1)
// Problem Link:https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/permutations-of-a-given-string2041

class Solution {
  public:
    void genPermuntations(int n,string&curr,unordered_map<char,int>&cnt,vector<string>&res){
        if (curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(pair<char,int>it:cnt){
            char c=it.first;
            int count=it.second;
            if(count==0)continue;
            curr.push_back(c);
            cnt[c]--;
            genPermuntations(n,curr,cnt,res);
            curr.pop_back();
            cnt[c]++;
        }
    }
    vector<string> findPermutation(string &s) {
        vector <string> res;
        unordered_map<char,int>cnt;
        for(char c:s)cnt[c]++;
        string curr="";
        genPermuntations(s.size(),curr,cnt,res);
        return res;
        
    }
};
