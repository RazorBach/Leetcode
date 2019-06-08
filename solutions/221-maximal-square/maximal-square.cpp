// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
//
// Input: 
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4
//


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int side[m + 1][n + 1];
        int maxlen = 0;
        for(int i = 0; i < n; ++i) {
            side[0][i] = 0;
        }
        for(int i = 1; i < m; ++i) {
            side[i][0] = 0;
        }
        for(int i = 1; i < m + 1; ++i)
            for(int j = 1; j < n + 1; ++j) {
                if(matrix[i - 1][j - 1] == '1') {
                    side[i][j] = std::min(std::min(side[i - 1][j], side[i][j - 1]), side[i - 1][j -1]) + 1;
                    maxlen = std::max(maxlen, side[i][j]);
                } else {
                    side[i][j] = 0;
                }
            }
        return maxlen * maxlen;
    }
};
