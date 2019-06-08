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
//


class Solution {
public:
    string minWindow(string s, string t) {
        int req = t.size();
        vector<int> sub(256, 0);
        for(int i = 0; i < req; ++i) {
            sub[t[i]]++;
        }
        int left = 0, right = 0, start = 0, len = INT_MAX;
        while(right < s.size()) {
            //move the right window
            while(req > 0) {
                if(right == s.size()) break;
                if(sub[s[right]] > 0) req--;
                //sub-- for all chars, those not in t will be negative
                sub[s[right]]--;
                right++;
            }
            //move the left window --todo
            while(0 == req && left < right) {
                if(0 == sub[s[left]] ) {
                    req++;
                    if(right - left < len) {
                        len = right - left;
                        start = left;
                    }
                }
                sub[s[left]]++;
                left++;
            }
            
        }
        if(len == INT_MAX)
            return "";
        return s.substr(start, len);
    }
};
