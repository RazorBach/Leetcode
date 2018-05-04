//
// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//
// Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sub(1, nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            auto idx = std::lower_bound(sub.begin(), sub.end(), nums[i]);
            if(idx == sub.end()) {
                sub.push_back(nums[i]);
            }else{
                *idx = nums[i];
            }
        }
        return sub.size();
    }
};
