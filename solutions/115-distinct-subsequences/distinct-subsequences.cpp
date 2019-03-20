// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
//
// Example 2:
//
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
//


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> mat(n + 1 , vector<int>(m + 1, 0));
        for(int i = 0; i < m + 1; ++i) {
            mat[0][i] = 1;
        }
        // for(int i = 1; i < n; ++i) {
        //     mat[i][0] = 0;
        // }
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < m + 1; ++j) {
                if(s[j - 1] == t[i - 1]){
                    mat[i][j] = mat[i - 1][j - 1] + mat[i][j - 1];
                }else{
                    mat[i][j] = mat[i][j - 1];
                }
            }
        }
        return mat[n][m];
    }
};
