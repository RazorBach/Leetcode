// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> letter(128, -1);
        int len(0), start(0), end(0);
        for(int i = 0; i < s.length(); ++i) {
            if(letter[s[i]] >= start) {
                start = letter[s[i]] + 1 ;
            }
            end = i;
            letter[s[i]] = i;
            if(end - start + 1 > len) {
                len = end - start + 1;
            }
        }
        return len;
    }
};
