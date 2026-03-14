// Problem: The k-th Lexicographical String of All Happy Strings of Length n (Daily Challenge -MAR 14)
// Approach: Backtracking
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
// Problem Link:https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

class Solution {
public:
    vector<string> res;

    void backtrack(string curr, int n){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}){
            if(curr.empty() || curr.back() != ch){
                backtrack(curr + ch, n);
            }
        }
    }

    string getHappyString(int n, int k) {

        backtrack("", n);

        if(k > res.size())
            return "";

        return res[k-1];
    }
};
