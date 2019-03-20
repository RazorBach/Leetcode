// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) 
            return ret;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            int sum = -nums[i];
            int lo(i + 1), hi(nums.size() - 1);
            while(lo < hi) {
                if((nums[lo] + nums[hi]) > sum) {
                        hi--;
                } else if((nums[lo] + nums[hi] < sum)) {
                        lo++;
                } else {
                    ret.push_back({nums[i] , nums[lo], nums[hi]});
                    do {
                        lo++;
                    } while(nums[lo] == nums[lo - 1]);
                    do {
                        hi--;
                    } while(nums[hi] == nums[hi + 1]);
                }
            }
            while(nums[i + 1] == nums[i])
                i++;
        }
        return ret;
    }
};
