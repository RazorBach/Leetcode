// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int maxlen = 0, start = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(')
                stack.push(i);
            else if(stack.empty()) {
                start = i + 1;
            }else{
                stack.pop();
                if(stack.empty()) {
                    maxlen = std::max(maxlen, i - start + 1);
                }else{
                    maxlen = std::max(maxlen, i - stack.top());
                }
            }
        }
        return maxlen;
    }
};
