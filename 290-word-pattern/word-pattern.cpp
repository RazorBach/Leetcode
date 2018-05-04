// Given a pattern and a string str, find if str follows the same pattern.
//  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Examples:
//
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
//
//
//
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//
//
// Credits:Special thanks to @minglotus6 for adding this problem and creating all test cases.


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, int> s2i;
        map<char, int> c2i;
        istringstream is(str);
        int i = 0,len = pattern.size();
        for(string word; is >> word; ++i) {
            if(i == len || s2i[word] != c2i[pattern[i]])
                return false;
            s2i[word] = c2i[pattern[i]] = i + 1;
        }
        return i == len;
            
    }
};
