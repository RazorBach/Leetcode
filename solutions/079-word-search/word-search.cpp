// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//


class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int m,int n,string word,int index){
        char cur;
        bool ret(false);
        if((cur = board[i][j]) != word[index]) return false;
        if(index == word.size() - 1) return true;
        board[i][j] = '*';
        if(i < m - 1) ret = dfs(board, i + 1, j, m, n, word, index + 1);
        if(!ret && j < n - 1) ret = dfs(board, i, j + 1, m, n, word, index + 1);
        if(!ret && i > 0) ret = dfs(board, i - 1, j, m, n, word, index + 1);
        if(!ret && j > 0) ret = dfs(board, i, j - 1, m, n, word, index + 1);
        board[i][j] = cur;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(dfs(board,i, j, m, n, word, 0)) return true;
            }
        }
        return false;
    }
};
