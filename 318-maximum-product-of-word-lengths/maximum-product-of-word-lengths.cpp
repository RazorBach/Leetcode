//
//     Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
//     You may assume that each word will contain only lower case letters.
//     If no such two words exist, return 0.
//
//
//
//     Example 1:
//
//
//     Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//     Return 16
//     The two words can be "abcw", "xtfn".
//
//
//     Example 2:
//
//
//     Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//     Return 4
//     The two words can be "ab", "cd".
//
//
//     Example 3:
//
//
//     Given ["a", "aa", "aaa", "aaaa"]
//     Return 0
//     No such pair of words.    
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
public:
int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());
    int result = 0;
    for (int i=0; i<words.size(); ++i) {
        for (char c : words[i])
            mask[i] |= 1 << (c - 'a');
        for (int j=0; j<i; ++j)
            if (!(mask[i] & mask[j]))
                result = max(result, int(words[i].size() * words[j].size()));
    }
    return result;
}
//     int maxProduct(vector<string>& words) {
//         int _maxpro = 0;
//         for(int i = 0; i < words.size(); ++i){
//             int lengthi = words[i].size();
//             for(int j = i + 1; j < words.size(); ++j){
//                 int lengthj = words[j].size();
//                 if(_maxpro > lengthj * lengthi)
//                     continue;
//                 if(!_isSame(words[i],words[j])){
//                     _maxpro = lengthj * lengthi;
//                 }
//             }
//         }
//         return _maxpro;
//     }
    
// private:
//     bool _isSame(string& str1, string& str2){
//         vector<int> iInt(26, 0);
//         for(char c : str1){
//             iInt[c - 'a'] = 1;
//         }
//         for(char c : str2){
//             if(iInt[c - 'a'] == 1)
//                 return true;
//         }
//         return false;
//     }
};
