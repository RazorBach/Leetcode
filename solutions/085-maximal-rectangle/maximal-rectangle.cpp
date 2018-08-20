// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = 0;
        //在heights末尾放个0作为哨兵
        vector<int> heights(n + 1, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ret = std::max(ret, maxHeights(heights));
        }
        return ret;
    }
private:
    int maxHeights(vector<int>& heights) {
        int maxarea = 0;
        stack<int> s;
        for(int i = 0; i < heights.size(); ++i) {
            while(!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int left = s.empty() ? -1 : s.top();
                maxarea = std::max(maxarea, h * (i - left - 1));
            }
            s.push(i);
        }
        return maxarea;
    }
};
