// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example: 
//
//
// Input: [2,3,1,2,4,3], s = 7
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
//


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int sum = nums[0], ret = INT_MAX;
        for(int p = 0, q = 1; q <= nums.size(); ) {
            if(sum < s) {
                if(q == nums.size())
                    break;
                sum += nums[q++];
            }else {
                ret = min(ret, q - p);
                sum -= nums[p++];
                if(p == q) {
                    sum = nums[q++];
                }
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
