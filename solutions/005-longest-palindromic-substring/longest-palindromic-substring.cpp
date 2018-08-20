// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        for(int i = 0; i < s.length(); ++i) {
            string tmp = longPal(s, i, i);
            string tmp2 = longPal(s, i, i + 1);
            tmp = tmp.size() > tmp2.size() ? tmp : tmp2;
            if(tmp.size() > ret.size())
                ret = tmp;
        }
        return ret;
    }
private:
    string longPal(string s, int i, int j) {
        int start(i), end(j);
        for(; start >= 0 && end < s.length(); start--, end++) {
            if(s[start] != s[end]) {
                break;
            }
        }
        start++;
        end--;
        return s.substr(start, end - start + 1);
    }
};
