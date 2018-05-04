// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,list<string>> map;
        for(string str:strs){
            string tmp = sortStr(str);
            if(map[tmp].empty())
                map[tmp] = list<string>(1,str);
            else
                map[tmp].push_back(str);
        }
        vector<vector<string>> ret;
        for(auto iter : map){
            ret.push_back(vector<string>(iter.second.begin(),iter.second.end()));
        }
        return ret;
    }
private:
    string sortStr(const string& str){
        int count[26] = {0},n = str.size();
        for(char c:str)
            count[c - 'a']++;
        string ret(n, 'a');
        int index = 0;
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < count[i]; ++j)
                ret[index++] += i;
        return ret;
    }
    
};
