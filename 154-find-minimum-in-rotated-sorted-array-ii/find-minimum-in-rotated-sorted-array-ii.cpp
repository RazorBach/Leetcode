// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// The array may contain duplicates.
//
// Example 1:
//
//
// Input: [1,3,5]
// Output: 1
//
// Example 2:
//
//
// Input: [2,2,2,0,1]
// Output: 0
//
// Note:
//
//
// 	This is a follow up for "Find Minimum in Rotated Sorted Array".
// 	Would allow duplicates affect the run-time complexity? How and why?
//
//


class Solution {
public:
    int findMin(vector<int>& nums) {
        // 一次ac代码！！
        // int lo = 0 , hi = nums.size() - 1;
        // while(lo < hi){
        //     int mid = (lo + hi) / 2;
        //     if(nums[mid] == nums[lo] && nums[mid] == nums[hi]){//无法判断哪边有序
        //         lo++;
        //         hi--;
        //         continue;
        //     }
        //     if(nums[mid] > nums[hi])
        //         lo = mid + 1;
        //     else if(nums[mid] < nums[hi])
        //         hi = mid;
        //     else{
        //         if(nums[mid] > nums[lo])
        //             return nums[lo];
        //         else
        //             hi = mid;
        //     }
        // }
        // return nums[lo];
        
        int lo = 0 , hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] > nums[hi])
                lo = mid + 1;
            else if(nums[mid] < nums[hi])
                hi = mid;
            else
                hi--;
        }
        return nums[lo];
    }
};
