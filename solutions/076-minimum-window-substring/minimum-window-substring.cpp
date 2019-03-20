// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//


class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto c : t) {
            map[c]++;
        }
        int minStart = 0, len = INT_MAX, start = 0, end = 0, cnt = t.size();
        while(end < s.size()) {
            if(map[s[end]] > 0) {
                cnt--;
            }
            map[s[end]]--;
            end++;
            while(0 == cnt) {
                if(end - start < len) {
                    len = end - start ;
                    minStart = start;
                }
                if(map[s[start]] == 0) {
                    cnt++;
                }
                map[s[start]]++;
                start++;
            }
        }
        if(len == INT_MAX)
            return "";
        return s.substr(minStart , len);
    }
};
