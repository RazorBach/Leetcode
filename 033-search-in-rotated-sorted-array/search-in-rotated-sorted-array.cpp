// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int p(0),q(nums.size() - 1);
        while(p <= q){
            int mid = (p + q) / 2;
            if(target > nums[mid]){
                if(nums[mid] >= nums[p] || target <= nums[q])
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
            else 
                return mid;
        }
        return -1;
    }
};
