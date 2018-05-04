// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int p(0),q(nums.size() - 1);
        while(p <= q){
            int mid = (p + q) / 2;
            if(target == nums[mid]) 
                return true;
            if(nums[mid] == nums[p] && nums[mid] == nums[q]){//无法判断哪边有序
                p++;
                q--;
                continue;
            } 
            if(target > nums[mid]){
                if(nums[mid] >= nums[p] || target <= nums[q]) // 左边有序 || 右边有序
                    p = mid + 1;
                else
                    q = mid - 1;
            }   
            else if(target < nums[mid]){
                if(nums[mid] <= nums[q] || target >= nums[p])
                    q = mid - 1;
                else
                    p = mid + 1;
            }
        }
        return false;
    }
};
