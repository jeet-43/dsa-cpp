// Problem: Online Stock Pan
// Approach: Monotonic Decreasing Stack
// Time Complexity: O(1)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
private:
    stack<pair<int, int>> st; 

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

