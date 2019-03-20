// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
//
// 	Insert a character
// 	Delete a character
// 	Replace a character
//
//
// Example 1:
//
//
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
//
// Example 2:
//
//
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
//
//


class Solution {
public:
    // //注意DP的边界条件！！注意赋予下标含义。
    // int minDistance(string word1, string word2) {
    //     int n1 = word1.size(), n2 = word2.size();
    //     if(!n1 || !n2) return n1 + n2;
    //     //minD(xi, yj) = minD(xi-1,yj-1) (xi == yj)
    //     //               min(minD(xi-1,yj-1),minD(xi-1,yj),minD(xi,yj-1)) + 1 (xi != yj)
    //     //
    //     int tmp[n1][n2];
    //     tmp[0][0] = !(word1[0] == word2[0]);
    //     for(int i = 1; i < n1; ++i){
    //         //当第二次相等时，也要+1，所以边界应该考虑空字符串
    //         if(word1[i] == word2[0]) {
    //             tmp[i][0] = tmp[i - 1][0];
    //         }else{
    //             tmp[i][0] = tmp[i - 1][0] + 1;
    //         }
    //     }
    //     for(int j = 1; j < n2; ++j){
    //         if(word1[0] == word2[j]) {
    //             tmp[0][j] = tmp[0][j - 1];
    //         }else{
    //             tmp[0][j] = tmp[0][j - 1] + 1;
    //         }
    //     }
    //     for(int i = 1; i < n1; ++i) {
    //         for(int j = 1; j < n2; ++j) {
    //             if(word1[i] == word2[j]) {
    //                 tmp[i][j] = tmp[i-1][j-1];
    //             }else {
    //                 tmp[i][j] = min(tmp[i-1][j-1], min(tmp[i-1][j], tmp[i][j-1])) + 1;
    //             }
    //         }
    //     }
    //     return tmp[n1 - 1][n2 - 1];
    // }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int tmp[n1 + 1][n2 + 1];
        tmp[0][0] = 0;
        for(int i = 1; i < n1 + 1; ++i) 
            tmp[i][0] = i;
        for(int j = 1; j < n2 + 1; ++j)
            tmp[0][j] = j;
        for(int i = 1; i < n1 + 1; ++i)
            for(int j = 1; j < n2 + 1; ++j){
                if(word1[i - 1] == word2[j - 1]) {
                    tmp[i][j] = tmp[i - 1][j - 1];
                }else
                    tmp[i][j] = min(tmp[i - 1][j - 1], min(tmp[i - 1][j], tmp[i][j - 1])) + 1;
            }
        return tmp[n1][n2];
    }
};
