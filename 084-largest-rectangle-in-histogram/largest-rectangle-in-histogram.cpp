// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//  
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//  
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        vector<int> index;
        for(int i = 0; i < heights.size(); ++i){
            while(index.size() > 0 && heights[index.back()] > heights[i]) {
                int h = heights[index.back()];
                index.pop_back();
                
                int si = index.size() > 0 ? index.back() : -1;
                ret = max(ret, h *(i - si - 1));
            }
            index.push_back(i);
        }
        return ret;
    }
};
