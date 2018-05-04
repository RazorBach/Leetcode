// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
//
//


class Solution {
public:
    // int bfs(vector<vector<int>> grid,int p,int q){
    //     if(p == 0 && q == 0)
    //         return grid[0][0];
    //     if(p > 0 && q == 0)
    //         return grid[p][q] + bfs(grid, p - 1, q);
    //     if(q > 0 && p == 0)
    //         return grid[p][q] + bfs(grid, p, q - 1);
    //     if(p > 0 && q > 0)
    //         return grid[p][q] + min(bfs(grid, p, q - 1),bfs(grid, p - 1, q));
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     return bfs(grid, grid.size() - 1, grid[0].size() - 1);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(),cols = grid[0].size();
        for(int i = 0; i < rows; ++i){
            grid[i][0] += i == 0 ? 0 : grid[i - 1][0];
            for(int j = 1; j < cols; ++j){
                grid[i][j] += i == 0 ? grid[i][j - 1]:min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[rows - 1][cols - 1];
    }
};
