// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix("");
        for(size_t t = 0; !strs.empty() ; prefix += strs[0][t],t++)
            for(string str : strs)
                if(t >= str.size() || str[t] != strs[0][t])
                    return prefix;
        return prefix;
      
    }
};
