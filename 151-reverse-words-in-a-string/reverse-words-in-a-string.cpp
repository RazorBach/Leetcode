// Given an input string, reverse the string word by word.
//
// Example:  
//
//
// Input: "the sky is blue",
// Output: "blue is sky the".
//
//
// Note:
//
//
// 	A word is defined as a sequence of non-space characters.
// 	Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// 	You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//
// Follow up: For C programmers, try to solve it in-place in O(1) space.
//


class Solution {
public:
      void reverseWords(string &s) {
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (idx != 0) s[idx++] = ' ';
                int j = i;
                while (j < s.size() && (s[idx] = s[j]) != ' ') {
                    idx++;
                    j++;
                }
                reverse(s.begin() + idx - j + i, s.begin() + idx);
                i = j;
            }
        }
        s.erase(s.begin() + idx, s.end());
        reverse(s.begin(), s.end());
    }
};
