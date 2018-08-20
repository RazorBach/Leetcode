// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo(0),hi(nums.size() - 1),mid;
        vector<int> ret(2,-1);
        //先找lo
        while(lo < hi){
            mid = (lo + hi) / 2;
            if(nums[mid] < target)
                lo = mid + 1;
            else 
                hi = mid;
        }
        //所有元素都小于target
        if(lo == nums.size()) return ret;
        //没有元素等于target
        if(nums[lo] != target) return ret;
        ret[0] = lo;
        //再找hi
        hi = nums.size() - 1;
        while(lo < hi){
            mid = (lo + hi) / 2 + 1;
            if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid;
        }
        ret[1] = hi;
        return ret;
    }
};
