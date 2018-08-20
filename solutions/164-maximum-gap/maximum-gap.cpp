// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
//
//
// 	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// 	Try to solve it in linear time/space.
//
//


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //桶排序 间隔为gap = ceil(max-min)/(n-1) 每个桶是[min + k*gap,min + (k + 1)* gap)
        int max_i = 0,min_i = INT_MAX,n = nums.size();
        if(n < 2) return 0;
        if(n == 2) return abs(nums[0] - nums[1]);
        for(int num : nums){
            if(num > max_i) max_i = num;
            if(num < min_i) min_i = num;
        }
        int gap = ceil(double(max_i - min_i) / (n - 1));
        if(!gap)
            return 0;
        vector<int> bucketmin(n, INT_MAX);
        vector<int> bucketmax(n, 0);
        for(int num : nums){
            int index = (num - min_i) / gap;
            if(num < bucketmin[index]) bucketmin[index] = num;
            if(num > bucketmax[index]) bucketmax[index] = num;
        }
        int prev = min_i;
        for(int i = 0; i < n; ++i){
            if(bucketmin[i]!= INT_MAX){ 
                gap = std::max(gap, bucketmin[i] - prev);
                prev = bucketmax[i];
            }
        }
        return gap;
    }
};
