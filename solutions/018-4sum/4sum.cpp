// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for(int m = 0; m < nums.size(); ++m){
            if(4 * nums[m] > target)
                break;
            int _tar3 = target - nums[m];
            for(int i = m + 1; i < nums.size(); ++i){
                if(3 * nums[i] > _tar3)
                    break;
                int _tar2 = _tar3 - nums[i];
                int lo = i + 1, hi = nums.size() - 1;
                while(lo < hi){
                    if(nums[lo] + nums[hi] < _tar2){
                        lo++;
                    }else if(nums[lo] + nums[hi] > _tar2){
                        hi--;
                    }else{
                        vector<int> tmp = {nums[m], nums[i], nums[lo], nums[hi]};
                        ret.push_back(tmp);
                        while(nums[lo + 1] == nums[lo]) lo++;
                        while(nums[hi - 1] == nums[hi]) hi--;
                        lo++;
                        hi--;
                    }
                }
                while(nums[i + 1] == nums[i]) i++;
            }
            while(nums[m + 1] == nums[m]) m++;
        }
        return ret;
    }
};
