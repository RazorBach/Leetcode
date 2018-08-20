// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    // vector<string> letterCombinations(string digits) {
    //     if(digits.empty())
    //             return vector<string>();
    //     vector<string> ret(1, string());
    //     for(char c : digits){
    //         int off = c - '2';
    //         if(off < 0)
    //             return vector<string>();
    //         int m = ret.size();
    //         for(int i = 0; i < m; ++i){
    //             string tmp = ret[i];
    //             if(off < 5){
    //                 ret[i].push_back('a' + 3 * off);
    //                 ret.push_back(tmp + char('a' + 3 * off + 1));
    //                 ret.push_back(tmp + char('a' + 3 * off + 2));
    //             }else if(off == 5){
    //                 ret[i].push_back('a' + 3 * off);
    //                 ret.push_back(tmp + char('a' + 3 * off + 1));
    //                 ret.push_back(tmp + char('a' + 3 * off + 2));
    //                 ret.push_back(tmp + char('a' + 3 * off + 3));
    //             }else if(off == 6){
    //                 ret[i].push_back('a' + 3 * off + 1);
    //                 ret.push_back(tmp + char('a' + 3 * off + 2));
    //                 ret.push_back(tmp + char('a' + 3 * off + 3));
    //             }else{
    //                 ret[i].push_back('a' + 3 * off + 1);
    //                 ret.push_back(tmp + char('a' + 3 * off + 2));
    //                 ret.push_back(tmp + char('a' + 3 * off + 3));
    //                 ret.push_back(tmp + char('a' + 3 * off + 4));
    //             }
    //         }
    //     }
    //     return ret;
    // }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return vector<string>();
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");   // add a seed for the initial case
        for(int i = 0 ; i < digits.size(); ++i) {
            int num = digits[i]-'0';
            if(num < 0 || num > 9) break;
            const string& candidate = v[num];
            if(candidate.empty()) continue;
            vector<string> tmp;
            for(int k = 0 ; k < result.size() ; ++k) {
                for(int j = 0 ; j < candidate.size() ; ++j) {
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};
