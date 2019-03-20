// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 从上到下 
        // int ret(triangle[0][0]);
        // vector<int> minV(triangle.back().size(),INT_MAX);
        // minV[0] = ret;
        // for(int t = 1; t < triangle.size(); ++t){
        //     for(int i = triangle[t].size() - 1; i >= 0; --i){
        //         minV[i] = min(minV[max(i - 1,0)],minV[i]) + triangle[t][i];
        //         if(t == triangle.size() - 1)
        //             ret = (i == triangle[t].size() - 1) ? minV[i] : min(ret,minV[i]);
        //     }
        // }
        // return ret;
        
        //可以从下至上
        vector<int> minlen(triangle.back());
        for(int t = triangle.size() - 2; t >= 0; --t){
            for(int i = 0; i < triangle[t].size(); ++i){
                minlen[i] = min(minlen[i],minlen[i+1]) + triangle[t][i];
            }
        }
        return minlen[0];
    }
};
