// Problem: Decode String
// Approach: Stack + state tracking
// Time Complexity: O(n*k)
// Space Complexity: O(n)
// Problem Link:https://leetcode.com/problems/decode-string/description/

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;

        string currentString = "";
        int currentNumber = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }
            else if (ch == '[') {
                numStack.push(currentNumber);
                strStack.push(currentString);

                currentNumber = 0;
                currentString = "";
            }
            else if (ch == ']') {
                int repeatTimes = numStack.top();
                numStack.pop();

                string prevString = strStack.top();
                strStack.pop();

                string temp = "";
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currentString;
                }

                currentString = prevString + temp;
            }
            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};
