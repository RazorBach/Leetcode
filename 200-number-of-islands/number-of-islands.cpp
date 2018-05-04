// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//
//


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int ret = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                    ret++;
                    dfs(grid, i, j, row, col);
                }
            }
        return ret;
    }
private:
    void dfs(vector<vector<char>>& grid, int m, int n,const int& row,const int& col) {
        if(grid[m][n] == '0' || grid[m][n] == '9') return;
        grid[m][n] = '9';
        if(m > 0)
            dfs(grid, m - 1, n, row, col);
        if(m < row - 1)
            dfs(grid, m + 1, n,row, col);
        if(n > 0)
            dfs(grid, m, n - 1, row, col);
        if(n < col - 1)
            dfs(grid, m, n + 1, row, col);
    }
};
