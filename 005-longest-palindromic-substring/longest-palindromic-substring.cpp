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
        int start = 0 , maxlength = !s.empty();
        for(int i = 0; i < s.length() ; ++i){
            // int len1 = _long(s, i, i);
            // int len2 = _long(s, i, i+1);
            // int len = max(len1, len2);
            int len = max(_long(s, i, i ), _long(s, i, i + 1));
            if(len > maxlength){
                start = i - (len - 1) / 2;
                maxlength = len;
            }
        }
        return s.substr(start, maxlength);
    }
private:
    int _long(string s,int left,int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};
