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
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> sub(256, -1);
        int maxlen = 0, last = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(sub[s[i]] > last) {
                last = sub[s[i]] ;
            }
            int tmp = i - last;
            maxlen = max(tmp, maxlen);
            sub[s[i]] = i;
        }
        return maxlen;
    }
};
