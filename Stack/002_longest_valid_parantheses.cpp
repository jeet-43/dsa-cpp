// Problem: Longest Valid Parantheses
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);   

        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);   
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

