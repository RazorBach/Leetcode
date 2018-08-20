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
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        vector<int> temp(grid[0].begin(), grid[0].end());
        for(int i = 1; i < temp.size(); ++i)
            temp[i] += temp[i - 1];
        for(int i = 1; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                temp[j] = (j == 0 ? temp[0] : std::min(temp[j-1], temp[j])) + grid[i][j]; 
            } 
        }
        return temp.back();
    }
};
