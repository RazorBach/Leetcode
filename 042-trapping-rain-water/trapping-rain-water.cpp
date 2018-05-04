// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6


class Solution {
public:
    int trap(vector<int> height) {
        if (height.empty()) return 0;
        stack<int> istack;
        istack.push(0);
        vector<int> value(height.size(), 0);
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] < height[istack.top()]) {
                istack.push(i);
                value[i] = value[i - 1];
            }
            else {
                int left;
                while (!istack.empty() && height[i] > height[istack.top()]) {
                    left = istack.top();
                    istack.pop();
                }
                left = istack.empty() ? left + 1: istack.top() + 1;
                int heightnow = istack.empty() ? height[left - 1] : height[i];
                int tmpnow = 0;
                for (int idx = left; idx < i; ++idx) {
                    tmpnow += heightnow - height[idx];
                }
                value[i] = value[left - 1] + tmpnow;
                istack.push(i);
            }
        }
        return value.back();
    }
};
